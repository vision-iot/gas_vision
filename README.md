# Gas Vision


## Descrição

O Gas Vision é um analisador de qualidade do ar desenvolvido para monitorar a qualidade do ar em ambientes de trabalho. O dispositivo é projetado para detectar a presença de gases e compostos orgânicos voláteis (VOCs) prejudiciais à saúde, fornecendo dados em tempo real para empresas tomarem medidas preventivas e garantir a segurança de seus funcionários.



## Funcionalidades

O Gas Vision atualmente tem na teoria as seguintes funcionalidades:

- **Detecção de GLP**: Mede a concentração de gás liquefeito de petróleo (GLP) em partes por milhão (ppm).
- Detecção de Álcool: Detecta a presença de álcool no ar em miligramas por litro (mg/L).
- Detecção de Monóxido de Carbono (CO): Mede a concentração de monóxido de carbono no ar em partes por milhão (ppm).
- Monitoramento da Qualidade do Ar: Monitora a qualidade do ar geral utilizando um sensor de qualidade do ar, fornecendo informações sobre a concentração de gases e partículas.
- Monitoramento de Temperatura e Umidade: Mede a temperatura e umidade relativa do ambiente.



## Estrutura do Projeto

O projeto está organizado da seguinte forma:

- **[`src/`](./src/)**: Pasta contendo o código fonte principal do analisador de qualidade do ar, desenvolvido para o microcontrolador ESP32-S3 N16R8.

- **[`boards/`](./boards/)**: Pasta contendo informações sobre as placas desenvolvidas para o projeto, incluindo arquivos de fabricação no formato Gerber.



## Componentes Utilizados

Os seguintes componentes são utilizados no projeto:

- **Microcontrolador**: ESP32-S3 N16R8
- **Sensor de GLP**: MQ-6
- **Sensor de Álcool**: MQ-3
- **Sensor de Monóxido de Carbono (CO)**: [Especificar o sensor de CO utilizado]
- **Sensor de Qualidade do Ar**: ENS160
- **Sensor de Temperatura e Umidade**: ATH21



## Funcionamento

O Gas Vision utiliza uma combinação de sensores para medir a concentração de diferentes gases e compostos no ar. Os sensores enviam dados para o microcontrolador, que processa as informações e as exibe em um display ou através de uma interface de rede.



## Especificações Técnicas

| Especificação | Valor |
|---|---|
| Microcontrolador | ESP32-S3 N16R8 |
| Sensor de GLP | MQ-6 |
| Sensor de Álcool | MQ-3 |
| Sensor de CO | ENS160 |
| Sensor de Qualidade do Ar | ENS160 |
| Sensor de Temperatura e Umidade | ATH21 |
| Faixa de Medição GLP | 200-10000 ppm |
| Faixa de Medição Álcool | 0.05-10 mg/L |
| Faixa de Medição CO | 400-65000 ppm |
| Comunicação | WiFi / LoRa |
| Alimentação | A definir |
| Dimensões | A definir |
| Peso | A definir |



## Considerações de Segurança

O Gas Vision é um dispositivo de segurança e deve ser utilizado com cautela. É importante seguir as instruções do manual do usuário e as medidas de segurança recomendadas para evitar acidentes.



## Direitos Autorais

Este projeto é de propriedade de [Lucas Rayan](https://www.linkedin.com/in/lucasrguerra/) e [Vitória das Dores](https://www.linkedin.com/in/vitoria-das-dores/). É proibido o uso, reprodução ou modificação do projeto sem a permissão expressa dos autores.
