#ifndef _CHARACTER_LCD_PRIVATE_H_ 
#define _CHARACTER_LCD_PRIVATE_H_   
  
  
/*******************************************************/  
/**************** Private Definitions ******************/  
/*******************************************************/  
  
/*Comment!: */ 
#define CHARACTER_LCD_NUM_OF_DATA_PINS 8

const u8 CHARACTER_LCD_u8Data_Pins[8]={CHARACTER_LCD_u8DATA0,CHARACTER_LCD_u8DATA1,CHARACTER_LCD_u8DATA2,CHARACTER_LCD_u8DATA3,
	CHARACTER_LCD_u8DATA4,CHARACTER_LCD_u8DATA5,CHARACTER_LCD_u8DATA6,CHARACTER_LCD_u8DATA7};
  
/*******************************************************/  
/*****************  Private Functions  *****************/  
/*******************************************************/  
#define GET_BIT(Reg,Bit_no)                   (((Reg)>>(Bit_no))&1)

void CHARACTER_LCD_voidInit(void);

void CHARACTER_LCD_voidWriteData(u8 Copy_u8Data);

void CHARACTER_LCD_voidWriteCommand(u8 Copy_u8Data);
  
#endif  
