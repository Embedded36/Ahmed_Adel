#ifndef _KEYPAD_PRIVATE_H_ 
#define _KEYPAD_PRIVATE_H_   



/*******************************************************/
/**************** Private Definitions ******************/
/*******************************************************/

/*Comment!: */
#define KEYPAD_u16UNPRESSED 0
#define KEYPAD_u16NOBOUNCING 0
#define KEYPAD_u8NUM_ROWS 4
#define KEYPAD_u8NUM_COLUMNS 4
#define KEYPAD_u8FLAG_UP   1
#define KEYPAD_u8COUNTER_LIMIT 2
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

static Keypad_u16Switches Keypad_u16State;

static Keypad_u16Switches Keypad_u16Bouncing_Flag;

static u8 Keypad_u8Unpressed_Counter_Array[16]={0};

static u8 Keypad_u8pressed_Counter_Array[16]={0};

const u8 Keypad_u8RowS_Array[KEYPAD_u8NUM_ROWS] =
	    {KEYPAD_u8ROW1,KEYPAD_u8ROW2,KEYPAD_u8ROW3,KEYPAD_u8ROW4};

const u8 Keypad_u8COLUMNS_Array[KEYPAD_u8NUM_COLUMNS] =
	    {KEYPAD_u8COLUMN1,KEYPAD_u8COLUMN2,KEYPAD_u8COLUMN3,KEYPAD_u8COLUMN4};

#endif  
