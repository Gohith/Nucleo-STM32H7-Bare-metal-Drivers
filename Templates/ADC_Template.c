/**
 *  This file shows how to use the ADC peripheral driver library
 */

#include <stdint.h>
#include <ADC.h>

//Read 3 ADC channels (0, 5, 12)

uint8_t adc_channels[3] = {
    0,      // CH0
    5,      // CH5
    12      // CH12
};

uint8_t adc_sample_times[3] = {
    2,      // Sample time for CH0
    2,      // Sample time for CH5
    2       // Sample time for CH12
};

int main(void)
{
    //Create ADC configuration
    ADC_config_t adc1_cfg;

    adc1_cfg.instance       = ADC1;          // Use ADC1
    adc1_cfg.channel_length = 3;             // Number of channels
    adc1_cfg.channels       = adc_channels;  // Pointer to channel list
    adc1_cfg.sample_times   = adc_sample_times;

    //ADC mode configuration
    adc1_cfg.mode = CONTINUOUS_MODE | OVERRUN_MODE;

    //Oversampling configuration
    adc1_cfg.oversample = ENABLE_REGULAR_OVERSAMPLE;

    //Initialize ADC
    ADC_init(&adc1_cfg);

    //Start ADC conversion
    ADC_Start(&adc1_cfg);

    //Read ADC values in a loop
    while (1)
    {
        uint16_t adc_value = ADC_Read(&adc1_cfg);
        (void)adc_value; // Prevent unused variable warning
    }
    return 0;
}
