/* C includes */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cJSON.h>



/* ESP32 includes */
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_timer.h>



/* Project includes */
#include "uart/main.h"
#include "adc/main.h"



/* Measurement definitions */
#define SAMPLES_PER_SECOND 2000
#define SAMPLE_PERIOD (1000000 / SAMPLES_PER_SECOND)



/* Global variables */
uint64_t samples_mean[2];
uint16_t read_interrupt_counter = 0;
bool make_calcs = false;
bool is_first_sample = true;



/* Function prototypes */
void readInterrupt(void *arguments);
uint16_t mapValue(uint16_t value, uint16_t from_min, uint16_t from_max, uint16_t to_min, uint16_t to_max);



/* Configurations */
esp_timer_create_args_t timer_readings_args = {
  .callback = &readInterrupt,
  .arg = NULL,
  .dispatch_method = ESP_TIMER_TASK,
  .name = "readInterrupt",
};



void app_main(void) {
	// Configure board
	initializeUART();
	calibrateADC();

	// Create and configure timer
	esp_timer_handle_t timer_readings;
	esp_timer_create(&timer_readings_args, &timer_readings);
	esp_timer_start_periodic(timer_readings, SAMPLE_PERIOD);

	// Loop function
	while (1) {
		if (make_calcs) {
			uint16_t glp_ppm = mapValue(samples_mean[0], 0, 4095, 0, 10000);
			float alcohol_mgpl = mapValue(samples_mean[1], 0, 4095, 0, 1000) / 100.0;

			printf("\nGLP: %d ppm\n", glp_ppm);
			printf("Alcohol: %.2f mg/L\n\n", alcohol_mgpl);

			make_calcs = false;
		}

		vTaskDelay(1);
	}
}



/*
  * Function to read the interrupt
  * 
  * @param arguments: The arguments to be passed
*/
void readInterrupt(void *arguments) {
	if (is_first_sample) {
		samples_mean[0] = getSample(GLP_SENSOR_CHANNEL);
		samples_mean[1] = getSample(ALCOHOL_SENSOR_CHANNEL);
		is_first_sample = false;
	} else {
		samples_mean[0] = (samples_mean[0] + getSample(GLP_SENSOR_CHANNEL)) / 2;
		samples_mean[1] = (samples_mean[1] + getSample(ALCOHOL_SENSOR_CHANNEL)) / 2;
	}

	read_interrupt_counter++;
	if (read_interrupt_counter == SAMPLES_PER_SECOND) {
		read_interrupt_counter = 0;
		make_calcs = true;
	}
}



/*
	* Function to map a value from a range to another
	*
	* @param value: The value to be mapped
	* @param from_min: The minimum value of the original range
	* @param from_max: The maximum value of the original range
	* @param to_min: The minimum value of the target range
	* @param to_max: The maximum value of the target range
	* @return The mapped value
*/
uint16_t mapValue(uint16_t value, uint16_t from_min, uint16_t from_max, uint16_t to_min, uint16_t to_max) {
	return (value - from_min) * (to_max - to_min) / (from_max - from_min) + to_min;
}