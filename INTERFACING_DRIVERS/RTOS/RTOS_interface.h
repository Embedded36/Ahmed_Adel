#ifndef _RTOS_INTERFACE_H_ 
#define _RTOS_INTERFACE_H_   

/*******************************************************/
/***************** Public Definitions ******************/
/*******************************************************/


/*******************************************************/
/*****************  Public Functions  ******************/
/*******************************************************/

/*Comment!:Initialize RTOS  */
void RTOS_voidInit(void);

/*Comment!:Start RTOS */
void RTOS_voidStart(u8* Copy_u8Start);

/*Comment!: Append task information to TCB array */
void RTOS_voidCreateTask(void (*Copy_pfvoidtaskptr)(void), u8 Copy_u8Periodicity);

#endif
