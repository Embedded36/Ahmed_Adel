#ifndef _ADC_PRIVATE_H_ 
#define _ADC_PRIVATE_H_   
  
  
/*******************************************************/  
/**************** Private Definitions ******************/  
/*******************************************************/  
  
/*Comment!: options of ADC reference voltage*/
#define ADC_u8EXTERNAL_REFERENCE 0
#define ADC_u8INTERNAL_REFERENCE 1
#define ADC_u8VCC                2
  
#define ADC_u8ADEN               7
#define ADC_u8ADSC               6

#define ADC_u8EIGHT_BITS         0
#define ADC_u8TEN_BITS           1

#define ADC_u8_NUMBER_OF_CHANNELS 8
#define ADC_u8NUMBER_OF_SAMPLES   8

#if ADC_u8RESOLUTION==ADC_u8TEN_BITS

#define ADC_u8ADLAR              0

#elif ADC_u8RESOLUTION==ADC_u8EIGHT_BITS

#define ADC_u8ADLAR              1

#else

#error "error at choosing resolution"

#endif

#if  ADC_u8VOLTAGE_REFERENCE==ADC_u8EXTERNAL_REFERENCE

#define ADC_u8REFS1              0
#define ADC_u8REFS0              0

#elif  ADC_u8VOLTAGE_REFERENCE==ADC_u8INTERNAL_REFERENCE

#define ADC_u8REFS1              1
#define ADC_u8REFS0              1

#elif  ADC_u8VOLTAGE_REFERENCE==ADC_u8VCC

#define ADC_u8REFS1              0
#define ADC_u8REFS0              1

#else

#error "error at selecting reference voltage "

#endif
/*******************************************************/
/***************** Register Addresses ******************/
/*******************************************************/

#define ADC_u8ADMUX  ((volatile u8*)(0x27))
#define ADC_u8ADCSRA ((volatile u8*)(0x26))
#define ADC_u8ADCH   ((volatile u8*)(0x25))
#define ADC_u8ADCL   ((volatile u8*)(0x24))

/*******************************************************/  
/*****************  Private Functions  *****************/  
/*******************************************************/  
#define CONC(x0,x1,x2,x3,x4,x5,x6,x7)         CONC_HELPER(x0,x1,x2,x3,x4,x5,x6,x7)
#define CONC_HELPER(y7,y6,y5,y4,y3,y2,y1,y0)  0b##y7##y6##y5##y4##y3##y2##y1##y0
#define CLR_BIT(Reg,Bit_no)                   ((Reg)&=(~(1<<(Bit_no))))
#define SET_BIT(Reg,Bit_no)                   ((Reg)|=(1<<(Bit_no)))
#define GET_BIT(Reg,Bit_no)                   (((Reg)>>(Bit_no))&1)
  
#endif  
