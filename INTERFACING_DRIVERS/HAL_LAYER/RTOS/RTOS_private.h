#ifndef _RTOS_PRIVATE_H_ 
#define _RTOS_PRIVATE_H_   
  
  
/*******************************************************/  
/**************** Private Definitions ******************/  
/*******************************************************/  
  
#define RTOS_u8DOWN_FLAG 0
  
#define RTOS_u8UP_FLAG   1

/*******************************************************/  
/*****************  Private Functions  *****************/  
/*******************************************************/  

/*Comment!:call back function of Timer0  */
void RTOS_voidCallBack(void);

/*Comment!:This function has the responsibility to execute tasks every system tick */
void RTOS_voidTaskManger(struct TCB *Copy_PStructTcp);

  
#endif  
