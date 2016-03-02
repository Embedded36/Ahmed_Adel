#include"../../APPLICATION_LAYER/types.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include"TACTILE_SWITCH_interface.h"  
#include"TACTILE_SWITCH_config.h" 
#include"TACTILE_SWITCH_private.h"

extern void TACTILE_SWITCH_voidInit(void)
    {

    /*Comment!: initiate  Switches  unPressed */
    Tactile_Switch_u16State.Tactile_Switches = TACTILE_SWITCH_INITIAL_UNPRESSED;

    /*Comment!: initiate  Switches' flags down */
    Tactile_Switch_u16Bouncing_Flag.Tactile_Switches = TACTILE_FLAG_INITIAL_DOWN;

    return;
    }

extern u8 TACTILE_SWITCH_u8Read(u8 Copy_u8SwitchIdx, u8* Copy_u8PtrToResult)
    {
    u8 local_u8ErrorFlag;
    u8 local_u8Switch_Current_State;
    u8 local_u8Switch_Last_State;
    u8 local_u8Bouncing_Flag;
    u8 local_u8Switch_Pressed_State;

    /*Comment!: Check Switch range*/
    if (Copy_u8SwitchIdx < TACTILE_SWITCH_u8SWITCHES_NUM)

	{

	/*Comment!: Read Switch value*/
	DIO_u8ReadPinVal(TACTILE_SWITCH_u8PIN_NUMBERS_ARRAY[Copy_u8SwitchIdx], &local_u8Switch_Current_State);

	/*Comment!: Read Switch's Last State*/
	local_u8Switch_Last_State = GET_BIT(Tactile_Switch_u16State.Tactile_Switches, Copy_u8SwitchIdx);

	/*Comment!: Read Switch Bouncing Flag*/
	local_u8Bouncing_Flag = GET_BIT(Tactile_Switch_u16Bouncing_Flag.Tactile_Switches, Copy_u8SwitchIdx);

	/*Comment!: Check Switch Pressed State DIO_u8HIGH ~ DIO_u8LOW*/
	local_u8Switch_Pressed_State = TACTILE_SWITCH_u8PRESSED_STATE_ARRAY[Copy_u8SwitchIdx];

	/*Comment!: Check Bouncing Flag*/
	if (local_u8Bouncing_Flag == TACTILE_SWITCH_FLAG_UP)
	    {

	    /*Comment!: Check Last State For Switch*/
	    if (local_u8Switch_Current_State != local_u8Switch_Pressed_State)
		{

		TACTILE_SWITCH_u8PIN_UNPRESSED_COUUNTER_ARRAY[Copy_u8SwitchIdx]++;

		TACTILE_SWITCH_u8PIN_PRESSED_COUNTER_ARRAY[Copy_u8SwitchIdx] = 0;

		}

	    else if (local_u8Switch_Current_State == local_u8Switch_Pressed_State)
		{

		TACTILE_SWITCH_u8PIN_PRESSED_COUNTER_ARRAY[Copy_u8SwitchIdx]++;

		TACTILE_SWITCH_u8PIN_UNPRESSED_COUUNTER_ARRAY[Copy_u8SwitchIdx] = 0;

		}

	    else
		{

		}

	    /*Comment!: Check Any Counter reach the limit*/
	    if (TACTILE_SWITCH_u8PIN_PRESSED_COUNTER_ARRAY[Copy_u8SwitchIdx] == TACTILE_SWITCH_COUNTER_LIMIT)

		{
		/*Comment!: Reset Pressed Counter*/
		TACTILE_SWITCH_u8PIN_PRESSED_COUNTER_ARRAY[Copy_u8SwitchIdx] = 0;

		/*Comment!: Make Bouncing Flag Low*/
		CLR_BIT(Tactile_Switch_u16Bouncing_Flag.Tactile_Switches, Copy_u8SwitchIdx);

		/*Comment!: Return Switch Statues as Pressed*/
		*Copy_u8PtrToResult = TACTILE_SWITCH_u8PRESSED;

		/*Comment!: Save Switch Statues as Pressed*/
		SET_BIT(Tactile_Switch_u16State.Tactile_Switches, Copy_u8SwitchIdx);

		}

	    else if (TACTILE_SWITCH_u8PIN_UNPRESSED_COUUNTER_ARRAY[Copy_u8SwitchIdx]
		    == TACTILE_SWITCH_COUNTER_LIMIT)

		{
		/*Comment!: Reset UnPressed Counter*/
		TACTILE_SWITCH_u8PIN_UNPRESSED_COUUNTER_ARRAY[Copy_u8SwitchIdx] = 0;

		/*Comment!: Make Bouncing Flag Low*/
		CLR_BIT(Tactile_Switch_u16Bouncing_Flag.Tactile_Switches, Copy_u8SwitchIdx);

		/*Comment!: Return Switch Statues as UnPressed*/
		*Copy_u8PtrToResult = TACTILE_SWITCH_u8UNPRESSED;

		/*Comment!: Save Switch Statues as UnPressed*/
		CLR_BIT(Tactile_Switch_u16State.Tactile_Switches, Copy_u8SwitchIdx);

		}

	    else

		{
		/*Comment!: Return Switch's Last state*/
		*Copy_u8PtrToResult = local_u8Switch_Last_State;

		}

	    }

	/*Comment!: Check if code is out of bouncing state*/
	else if (local_u8Bouncing_Flag == TACTILE_SWITCH_BOUNCING_FLAG_DOWN)
	    {

	    /*Comment!: Check Switch's Last state*/
	    switch (local_u8Switch_Last_State)
		{

	    case TACTILE_SWITCH_u8UNPRESSED:

		    /*Comment!: Check if switch is pressed*/
		if (local_u8Switch_Current_State == local_u8Switch_Pressed_State)
		    {

		    /*Comment!: Rise Bouncing Flag*/
		    SET_BIT(Tactile_Switch_u16Bouncing_Flag.Tactile_Switches, Copy_u8SwitchIdx);

		    }

		else
		    {

		    }

		/*Comment!: Return Switch as UnPressed*/
		*Copy_u8PtrToResult = TACTILE_SWITCH_u8UNPRESSED;

		break;

	    case TACTILE_SWITCH_u8PRESSED:

		    /*Comment!: Check if switch is UnPressed*/
		if (local_u8Switch_Current_State != local_u8Switch_Pressed_State)
		    {

		    /*Comment!: Rise Bouncing Flag*/
		    SET_BIT(Tactile_Switch_u16Bouncing_Flag.Tactile_Switches, Copy_u8SwitchIdx);

		    }

		else
		    {

		    }

		/*Comment!: Return Switch as Pressed*/
		*Copy_u8PtrToResult = TACTILE_SWITCH_u8PRESSED;

		break;

	    default:

		break;

		}

	    }

	else
	    {

	    }

	local_u8ErrorFlag = ok;

	}

    else
	{

	local_u8ErrorFlag = error;

	}

    return local_u8ErrorFlag;
    }
