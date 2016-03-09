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
#define ADC_u8RESOLUTION          ADC_u8TEN_BITS

#endif 
