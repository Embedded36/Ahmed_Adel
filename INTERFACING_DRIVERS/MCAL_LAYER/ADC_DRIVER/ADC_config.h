#ifndef _ADC_CONFIG_H_ 
#define _ADC_CONFIG_H_ 
  
  
/*******************************************************/  
/**************** Public Definitions *******************/  
/*******************************************************/  
  
/*Comment!: reference for ADC*/
/*Range!  : ADC_u8EXTERNAL_REFERENCE or ADC_u8INTERNAL_REFERENCE or ADC_u8VCC */
#define ADC_u8VOLTAGE_REFERENCE	ADC_u8VCC

/*Comment!: Resolution of  ADC*/
/*Range!  : ADC_u8EIGHT_BITS-ADC_u8TEN_BITS */
#define ADC_u8RESOLUTION          ADC_u8EIGHT_BITS

/*Comment!: Microcontroller supply voltage*/
/*Range!  : 0~5*/
#define ADC_u8VSUPPLY               5

/*Comment!: ADC internal voltage*/
/*Range!  : 0~ADC_u8VCC*/
#define ADC_u8VINTERNAL         2.56

/*Comment!: ADC external voltage*/
/*Range!  : 0~ADC_u8VCC*/
#define ADC_u8VEXTERNAL           5

#endif 
