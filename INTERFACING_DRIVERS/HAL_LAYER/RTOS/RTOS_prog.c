#include"../../Shared_Libraries/types.h"
#include "../../Shared_Libraries/interrupt.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include"../../MCAL_LAYER/TIMER0/TIMER0_interface.h"
#include"RTOS_interface.h"  
#include"RTOS_config.h" 
#include"RTOS_private.h"

/*Comment!: This flag is raised every system tick */
static u8 RTOS_u8InterruptFlag;

/*Comment!:Number of Tasks*/
static u8 RTOS_u8TaskNum;

/*Comment!:This variable show how many ticks the task has to wait to be executed*/
//its configured with initial task num ,it should be configured with max task num(255) but
//there isn't enough memory
static u8 RTOS_u8TaskPeriodicity[RTOS_u8TASKNUM];

void RTOS_voidInit(void)
    {

    /*Comment!: Initialize number of tasks */
    RTOS_u8TaskNum = RTOS_u8TASKNUM;

    /*Comment!: set interrupt flag down */
   // RTOS_u8InterruptFlag = RTOS_u8DOWN_FLAG;
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

void RTOS_voidStart(struct TCB *Copy_PStructTcp)
    {

    u8 Local_u8LoopCounter;

    for(Local_u8LoopCounter=0; Local_u8LoopCounter<RTOS_u8TaskNum;Local_u8LoopCounter++)

	{
	    /*Comment!: copy periodicity of every task */
	RTOS_u8TaskPeriodicity[Local_u8LoopCounter]=(Copy_PStructTcp[Local_u8LoopCounter].count);

	}

	    while (1)
		{

		if (RTOS_u8InterruptFlag)

		    {

		    /*Comment!: Restart Timer */
		    TIMER0_Void_Delay_MS(RTOS_u16TickTime);

		    /*Comment!: Execute Tasks */
		    RTOS_voidTaskManger(Copy_PStructTcp);

		    /*Comment!: set interrupt flag down */
		    RTOS_u8InterruptFlag = RTOS_u8DOWN_FLAG;

		    }
		else
		    {

		    }
		}

	    return;

	    }

	void RTOS_voidTaskManger(struct TCB *Copy_PStructTcp)
	    {

	    u8 Local_u8LoopCounter;

	    for (Local_u8LoopCounter = 0; Local_u8LoopCounter < RTOS_u8TaskNum; Local_u8LoopCounter++)

		{

		    /*Comment!: Check if Task should be executed*/
		if (RTOS_u8TaskPeriodicity[Local_u8LoopCounter])
		    {
		    /*Comment!: Decrement waiting time*/
		    RTOS_u8TaskPeriodicity[Local_u8LoopCounter]--;

		    }
		else
		    {

		    /*Comment!: Rest waiting time to periodicity*/
		    RTOS_u8TaskPeriodicity[Local_u8LoopCounter]=(Copy_PStructTcp[Local_u8LoopCounter].count);

		    /*Comment!: Execute task*/
		    (Copy_PStructTcp[Local_u8LoopCounter].ptr)();
		    }

		}

	    return;
	    }
