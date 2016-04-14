#ifndef _KEYPAD_PRIVATE_H_ 
#define _KEYPAD_PRIVATE_H_   

/*******************************************************/
/**************** Private Definitions ******************/
/*******************************************************/

#define KEYPAD_u16UNPRESSED     0
#define KEYPAD_u8NUM_ROWS       4
#define KEYPAD_u8NUM_COLUMNS    4
#define KEYPAD_u8SWITCH_PRESSED KEYPAD_u8PRESSEDSTATE

/*******************************************************/
/*****************  Private Functions  *****************/
/*******************************************************/

#define CLR_BIT(Reg,Bit_no)                   ((Reg)&=(~(1<<(Bit_no))))
#define GET_BIT(Reg,Bit_no)                   (((Reg)>>(Bit_no))&1)
#define SET_BIT(Reg,Bit_no)                   ((Reg)|=(1<<(Bit_no)))

#endif  
