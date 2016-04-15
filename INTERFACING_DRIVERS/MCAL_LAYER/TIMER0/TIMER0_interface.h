#ifndef _TIMER_INTERFACE_H_ 
#define _TIMER_INTERFACE_H_   

/*******************************************************/
/***************** Public Definitions ******************/
/*******************************************************/

/*Comment!: */

/*******************************************************/
/*****************  Public Functions  ******************/
/*******************************************************/

extern void TIMER0_VoidINIT();

extern void TIMER0_Void_Delay_US(u32 Copy_u32Us);

extern void TIMER0_Void_Delay_MS(u32 Copy_u32Us);


extern void TIMER0_CallbackSetup(void (*Copy_PvoidTimer0ISR)(void));

//  extern u16 TIMER0_u16readMS(void);
//
//  extern void TIMER0_voidReset(void);

#endif  
