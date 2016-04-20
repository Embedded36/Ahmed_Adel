#ifndef _RTOS_INTERFACE_H_ 
#define _RTOS_INTERFACE_H_   

/*******************************************************/
/***************** Public Definitions ******************/
/*******************************************************/

/*Comment!: TCB structure contain pointer to a void function (task),count represents Task's periodicity*/
/*Comment!:  counter = (Task Period) / (Tick Time)  */
struct TCB
    {
	void (*ptr)(void);
	u8 count;
    };

/*******************************************************/
/*****************  Public Functions  ******************/
/*******************************************************/

/*Comment!:Initialize RTOS  */
void RTOS_voidInit(void);

/*Comment!:Start RTOS */
void RTOS_voidStart(struct TCB *Copy_PStructTcp);

#endif
