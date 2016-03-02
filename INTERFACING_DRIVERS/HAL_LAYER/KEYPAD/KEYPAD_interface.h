#ifndef _KEYPAD_INTERFACE_H_ 
#define _KEYPAD_INTERFACE_H_   
  
  /*******************************************************/
/********************** NEW TYPE ***********************/
/*******************************************************/
typedef union
    {
	u16 KEYPAD_u16Switches;
	struct
	    {
		u16 KEYPAD_u8Switch1 :1;
		u16 KEYPAD_u8Switch2 :1;
		u16 KEYPAD_u8Switch3 :1;
		u16 KEYPAD_u8Switch4 :1;
		u16 KEYPAD_u8Switch5 :1;
		u16 KEYPAD_u8Switch6 :1;
		u16 KEYPAD_u8Switch7 :1;
		u16 KEYPAD_u8Switch8 :1;
		u16 KEYPAD_u8Switch9 :1;
		u16 KEYPAD_u8Switch10 :1;
		u16 KEYPAD_u8Switch11 :1;
		u16 KEYPAD_u8Switch12 :1;
		u16 KEYPAD_u8Switch13 :1;
		u16 KEYPAD_u8Switch14 :1;
		u16 KEYPAD_u8Switch15 :1;
		u16 KEYPAD_u8Switch16 :1;
	    };
    } Keypad_u16Switches;

/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  
  
/*Comment!: */ 
  
  
/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  
/*Comment!: Initialization Function */
extern void KEYPAD_voidInit(void);

/*Comment!:Read Switch */
extern Keypad_u16Switches KEYPAD_Keypad_u16SwitchesRead(void);
  
#endif  
