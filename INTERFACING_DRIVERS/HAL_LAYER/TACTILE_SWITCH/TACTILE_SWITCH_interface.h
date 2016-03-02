#ifndef _TACTILE_SWITCH_INTERFACE_H_ 
#define _TACTILE_SWITCH_INTERFACE_H_   
  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  
  
/*Comment!: Switches Ids */
 #define TACTILE_SWITCH_u8SWITCH1ID      0
 #define TACTILE_SWITCH_u8SWITCH2ID      1
 #define TACTILE_SWITCH_u8SWITCH3ID      2
 #define TACTILE_SWITCH_u8SWITCH4ID      3
 #define TACTILE_SWITCH_u8SWITCH5ID      4
 #define TACTILE_SWITCH_u8SWITCH6ID      5
 #define TACTILE_SWITCH_u8SWITCH7ID      6
 #define TACTILE_SWITCH_u8SWITCH8ID      7
 #define TACTILE_SWITCH_u8SWITCH9ID      8
 #define TACTILE_SWITCH_u8SWITCH10ID     9
 #define TACTILE_SWITCH_u8SWITCH11ID     10
 #define TACTILE_SWITCH_u8SWITCH12ID     11
 #define TACTILE_SWITCH_u8SWITCH13ID     12
 #define TACTILE_SWITCH_u8SWITCH14ID     13
 #define TACTILE_SWITCH_u8SWITCH15ID     14
 #define TACTILE_SWITCH_u8SWITCH16ID     15

/*Comment!: Switches States */
#define TACTILE_SWITCH_u8UNPRESSED 0
#define TACTILE_SWITCH_u8PRESSED   1
#define TACTILE_SWITCH_u8BOUNCING  2

/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  

/*Comment!: Initialization Function */
extern void TACTILE_SWITCH_voidInit(void);
  
/*Comment!:Read Switch */
extern u8 TACTILE_SWITCH_u8Read(u8 Copy_u8SwitchIdx, u8* Copy_u8PtrToResult);
  
#endif  
