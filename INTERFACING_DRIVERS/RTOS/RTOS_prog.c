#include"../Shared_Libraries/types.h"
#include "../Shared_Libraries/interrupt.h"
#include"../MCAL_LAYER/TIMER0/TIMER0_interface.h"
#include"RTOS_interface.h"  
#include"RTOS_config.h" 
#include"RTOS_private.h"

/*Comment!: This flag is raised every system tick */
static u8 RTOS_u8InterruptFlag;

/*Comment!: Initialize number of tasks */
static u8 RTOS_u8TaskNum=0;

/*Comment!:Tcb array*/
struct TCB RTOS_structtcbTCB_ARRay[RTOS_u8MAXTASKNUM];

/*Comment!:This variable show how many ticks the task has to wait to be executed*/
static u8 RTOS_u8TaskSWaitingTime[RTOS_u8MAXTASKNUM];

void RTOS_voidInit(void)
    {

    /*Comment!: set interrupt flag down */
    RTOS_u8InterruptFlag = RTOS_u8UP_FLAG;

    /*Comment!: Initialize timer module */
    TIMER0_VoidINIT();

    /*Comment!: set call back function for timer0 interrupt*/
    TIMER0_CallbackSetup(RTOS_voidCallBack);

    /*Comment!: enable global interrupt*/
    Enable_Global_INT();

    return;
    }

void RTOS_voidCallBack(void)
    {

    /*Comment!: set interrupt flag up */
    RTOS_u8InterruptFlag = RTOS_u8UP_FLAG;

    return;
    }

void RTOS_voidCreateTask(void (*Copy_pfvoidtaskptr)(void), u8 Copy_u8Periodicity)
    {

    /*Comment!: add task's pointer its TCB  */
    RTOS_structtcbTCB_ARRay[RTOS_u8TaskNum].ptr = Copy_pfvoidtaskptr;

    /*Comment!: add task's periodicity its TCB  */
    RTOS_structtcbTCB_ARRay[RTOS_u8TaskNum].periodicity = Copy_u8Periodicity;

    /*Comment!: increment number of tasks */
    RTOS_u8TaskNum++;

    return;
    }

void RTOS_voidStart(u8* Copy_u8Start)
    {

    u8 Local_u8LoopCounter;


    /*Comment!: adding first delay */
        for (Local_u8LoopCounter = 0; Local_u8LoopCounter < RTOS_u8TaskNum; Local_u8LoopCounter++)

    	{

            RTOS_u8TaskSWaitingTime[Local_u8LoopCounter]=Copy_u8Start[Local_u8LoopCounter];
    	}

    while (1)
	{

	if (RTOS_u8InterruptFlag)

	    {

	    /*Comment!: Restart Timer */
	    TIMER0_Void_Delay_MS(RTOS_u16TickTime);

	    /*Comment!: Execute Tasks */
	    RTOS_voidTaskManger();

	    /*Comment!: set interrupt flag down */
	    RTOS_u8InterruptFlag = RTOS_u8DOWN_FLAG;

	    }
	else
	    {

	    }
	}

    return;

    }

void RTOS_voidTaskManger()
    {

    u8 Local_u8LoopCounter;

    for (Local_u8LoopCounter = 0; Local_u8LoopCounter < RTOS_u8TaskNum; Local_u8LoopCounter++)

	{

	/*Comment!: Check if Task should be executed*/
	if (RTOS_u8TaskSWaitingTime[Local_u8LoopCounter])
	    {

	    /*Comment!: Decrement waiting time*/
	    RTOS_u8TaskSWaitingTime[Local_u8LoopCounter]--;

	    }
	else
	    {

	    /*Comment!: Rest waiting time to periodicity*/
	    RTOS_u8TaskSWaitingTime[Local_u8LoopCounter] = (RTOS_structtcbTCB_ARRay[Local_u8LoopCounter].periodicity);

	    /*Comment!: Execute task*/
	    (RTOS_structtcbTCB_ARRay[Local_u8LoopCounter].ptr)();
	    }

	}

    return;
    }
