//DEFINES AND INCLUDES
#include <atmel_start.h>
#define ADC_CHANNEL_10	10
#define ADC_10_BUFFER_SIZE 2
#define ADC_10_REFERENCE  2.229729729730	//VDC INTERNAL
#define ADC_16_BIT_FSR 32768	//FULL SCALE RANGE FOR SIGNED 16 BIT VARIABLE

// GLOBAL VARIABLES
uint16_t	ADC_10_value = 0;		//16 BIT UNSIGNED INTEGER FOR SINGLE ENDED (ALWAYS POSITVE)
float		ADC_10_volts = 0;		//INITIALIZE AS 0

int main(void)
{
	atmel_start_init();
	adc_sync_enable_channel(&ADC_10, ADC_CHANNEL_10);

	while (1)
	{
	
	ADC_10_read();
	delay_ms(50);
	
	}
	
}//END OF MAIN


void ADC_10_read(void)
{
uint8_t ADC_10_buffer[ADC_10_BUFFER_SIZE];

/* //////////////////////////////////////////////////////
 * ADC READ CONFIGURATION SUMMARY
 * ADC CHANNEL:			 0 (-) PA02/A0 
 * ADC CHANNEL:			10 (+) PB02/A1 
 * ADC MODE:			DIFFERENTIAL	
 * ADC CLOCK SOURCE:	GENERIC CLOCK 2 >> [OSC32K] HIGH-ACCURACY @ 32,768 Hz
 * RESOLUTION:			16 BIT *SIGNED*
 * AVERAGED SAMPLES:	32
 * VOLTAGE REFERENCE:	2.23 VDC INTERNAL
 *////////////////////////////////////////////////////////

adc_sync_read_channel(&ADC_10, ADC_CHANNEL_10, ADC_10_buffer, ADC_10_BUFFER_SIZE);
ADC_10_value = ADC_10_buffer[1];									//See adcbuff value
ADC_10_value = ADC_10_value << 8;									//Moving to the upper 8 bits
ADC_10_value = ADC_10_value | ADC_10_buffer[0];						//Appending lower 8 bit value to previous value			//16-bit ADC value:
ADC_10_value = ADC_10_buffer[1] << 8 | ADC_10_buffer[0];			//16 BIT VAL IS ELEMENT [1] SHIFTED 8 BITWISE OR [0] VALUE
//Calculating Voltage of ADC 10
ADC_10_volts = ((float)ADC_10_value * (float)ADC_10_REFERENCE / (float)ADC_16_BIT_FSR);

}

void delay_example(void)
{
	delay_ms(1000);
}
