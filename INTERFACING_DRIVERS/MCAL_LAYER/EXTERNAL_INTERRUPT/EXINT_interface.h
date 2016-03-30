#ifndef _EXINT_INTERFACE_H_ 
#define _EXINT_INTERFACE_H_   
  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  
  
/*Comment!: */ 
#define EXINT_u8INT0 6

#define EXINT_u8INT1 7

#define EXINT_u8INT2 5

#define EXINT_u8RISINGEDGE 0

#define EXINT_u8FALINGEDGE 1

#define EXINT_u8LOWLEVEL   2

#define EXINT_u8LEVELCHANGE   3

/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  
extern void EXINT_voidInit(void);

extern u8 EXINT_voidSetMode(u8 Copy_u8IntId, u8 Copy_u8IntMode);

extern u8 EXINT_ENABLEINT(u8 Copy_u8IntId);

extern u8 EXINT_DISABLEINT(u8 Copy_u8IntId);

extern void EXINT_ISR0CallBackSet(void (*Copy_PvoidEXINT2ISR)(void));

extern void EXINT_ISR1CallBackSet(void (*Copy_PvoidEXINT2ISR)(void));

extern void EXINT_ISR2CallBackSet(void (*Copy_PvoidEXINT2ISR)(void));

#endif  
