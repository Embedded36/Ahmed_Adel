#ifndef _ADC_INTERFACE_H_ 
#define _ADC_INTERFACE_H_   
  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  
  
/*Comment!: */ 
#define ADC_u8Channel0   0
#define ADC_u8Channel1   1
#define ADC_u8Channel2   2
#define ADC_u8Channel3   3
#define ADC_u8Channel4   4
#define ADC_u8Channel5   5
#define ADC_u8Channel6   6
#define ADC_u8Channel7   7
  
/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  
void ADC_voidInit(void);
  
u8 ADC_u8ReadGroup(u16* local_pu16Result);

u8 ADC_u8Read_Channel_One_Shot(u8 Copy_u8Channel_Num, u16* Copy_pu16Result);

u8 ADC_u8Read_Channel_Multi_Shot(u8 Copy_u8Channel_Num, u16* Copy_pu16Result);

void ADC_voidEnable(void);

void ADC_voidDisable(void);


#endif  
