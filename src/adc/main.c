#include "main.h"



/*
    * ADC Configuration
*/
adc_cali_handle_t calibration_handle;
adc_cali_curve_fitting_config_t calibration_config = {
    .atten = ADC_ATTENUATION,
    .bitwidth = ADC_BITWIDTH,
};



/*
	* Function to calibrate the ADC
*/
void calibrateADC() {
    gpio_set_direction(GLP_SENSOR_PIN, GPIO_MODE_INPUT);
    gpio_set_direction(ALCOHOL_SENSOR_PIN, GPIO_MODE_INPUT);

    adc1_config_width(ADC_WIDTH_BIT_12);

    adc1_config_channel_atten(GLP_SENSOR_CHANNEL, ADC_ATTENUATION);
    adc1_config_channel_atten(ALCOHOL_SENSOR_CHANNEL, ADC_ATTENUATION);
    
    adc_cali_create_scheme_curve_fitting(&calibration_config, &calibration_handle);
}



/*
	* Function to get the voltage from a specific channel
	* 
	* @param channel: The channel to be read
	* @return uint16_t: The voltage value
*/
uint16_t getSample(adc1_channel_t channel) {
	int sample = 0;
	adc_cali_raw_to_voltage(calibration_handle, adc1_get_raw(channel), &sample);
	return (uint16_t) sample;
}
