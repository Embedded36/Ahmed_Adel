#include"../../../APPLICATION_LAYER/types.h"
#include"../../../APPLICATION_LAYER/Delay.h"
#include"../../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include"../CHARACTER_LCD_interface.h"

 int main()
     {

     DIO_voidInit();

     CHARACTER_LCD_voidInit();

     //goto cgram
     CHARACTER_LCD_voidWriteCommand(0b01000000);

     CHARACTER_LCD_voidWriteData(0xff);
     CHARACTER_LCD_voidWriteData(0x00);
     CHARACTER_LCD_voidWriteData(0xff);
     CHARACTER_LCD_voidWriteData(0x00);

     CHARACTER_LCD_voidWriteData(0xff);
     CHARACTER_LCD_voidWriteData(0x00);
     CHARACTER_LCD_voidWriteData(0xff);
     CHARACTER_LCD_voidWriteData(0x00);
//goto ddram
     //CHARACTER_LCD_voidWriteCommand(0x80);
//     CHARACTER_LCD_voidWriteCommand(0b11000000);  start of line 2

     CHARACTER_LCD_voidWriteCommand(0b11000000);


     CHARACTER_LCD_voidWriteData(0x00);


     return 0;

     }

