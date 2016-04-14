#ifndef _TACTILE_SWITCH_PRIVATE_H_ 
#define _TACTILE_SWITCH_PRIVATE_H_   

/*******************************************************/
/********************** NEW TYPE ***********************/
/*******************************************************/
typedef union
    {
	u16 Tactile_Switches;
	struct
	    {
		u16 Tactile_Switch_u8Switch1 :1;
		u16 Tactile_Switch_u8Switch2 :1;
		u16 Tactile_Switch_u8Switch3 :1;
		u16 Tactile_Switch_u8Switch4 :1;
		u16 Tactile_Switch_u8Switch5 :1;
		u16 Tactile_Switch_u8Switch6 :1;
		u16 Tactile_Switch_u8Switch7 :1;
		u16 Tactile_Switch_u8Switch8 :1;
		u16 Tactile_Switch_u8Switch9 :1;
		u16 Tactile_Switch_u8Switch10 :1;
		u16 Tactile_Switch_u8Switch11 :1;
		u16 Tactile_Switch_u8Switch12 :1;
		u16 Tactile_Switch_u8Switch13 :1;
		u16 Tactile_Switch_u8Switch14 :1;
		u16 Tactile_Switch_u8Switch15 :1;
		u16 Tactile_Switch_u8Switch16 :1;
	    };
    } Tactile_Switch_u16Switches;

/*******************************************************/
/**************** Private Definitions ******************/
/*******************************************************/

/*Comment!: Initial Value For Switches as unPressed */
#define TACTILE_SWITCH_INITIAL_UNPRESSED   0
#define TACTILE_FLAG_INITIAL_DOWN          0
#define TACTILE_SWITCH_BOUNCING_FLAG_DOWN  0
#define TACTILE_SWITCH_FLAG_UP             1
#define TACTILE_SWITCH_COUNTER_LIMIT       5

/*******************************************************/
/*****************  Private Functions  *****************/
/*******************************************************/

/*Comment!: */
#define CLR_BIT(Reg,Bit_no)                   ((Reg)&=(~(1<<(Bit_no))))
#define GET_BIT(Reg,Bit_no)                   (((Reg)>>(Bit_no))&1)
#define SET_BIT(Reg,Bit_no)                   ((Reg)|=(1<<(Bit_no)))

#endif  
