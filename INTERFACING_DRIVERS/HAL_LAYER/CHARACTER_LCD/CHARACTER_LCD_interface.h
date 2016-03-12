#ifndef _CHARACTER_LCD_INTERFACE_H_ 
#define _CHARACTER_LCD_INTERFACE_H_   
  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  
  
/*Comment!: */ 
  
  
/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  void CHARACTER_LCD_voidInit(void);
  
  void CHARACTER_LCD_voidWriteCommand(u8 Copy_u8Command);

  void CHARACTER_LCD_voidWriteData(u8 Copy_u8Data);

  
#endif  
