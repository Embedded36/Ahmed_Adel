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

/******************************************************/
/********************** Arrays ************************/
/******************************************************/

/*Comment!: mapping to DIO pins of rows and columns*/
const u8 Keypad_u8RowS_Array[KEYPAD_u8NUM_ROWS] =
    {
    KEYPAD_u8ROW1, KEYPAD_u8ROW2, KEYPAD_u8ROW3, KEYPAD_u8ROW4
    };

const u8 Keypad_u8COLUMNS_Array[KEYPAD_u8NUM_COLUMNS] =
    {
    KEYPAD_u8COLUMN1, KEYPAD_u8COLUMN2, KEYPAD_u8COLUMN3, KEYPAD_u8COLUMN4
    };

#endif  
