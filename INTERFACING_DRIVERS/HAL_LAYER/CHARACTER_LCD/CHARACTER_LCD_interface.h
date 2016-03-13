#ifndef _CHARACTER_LCD_INTERFACE_H_ 
#define _CHARACTER_LCD_INTERFACE_H_   
  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  
  
/*Comment!: */ 
#define CHARACTER_LCD_u8LINE_1   0

#define CHARACTER_LCD_u8LINE_2   1

#define CHARACTER_LCD_u8AllLines 2
  
/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  void CHARACTER_LCD_voidInit(void);
  
  u8 CHARACTER_LCD_voidClear(u8 Local_u8LineId);
  
  u8 CHARACTER_LCD_voidWrite(u8* Copy_u8String, u8 Copy_u8Line, u8 Copy_u8CharId);

  #endif
