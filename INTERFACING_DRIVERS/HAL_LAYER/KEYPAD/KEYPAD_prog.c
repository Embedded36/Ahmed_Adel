#include"../../APPLICATION_LAYER/types.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include"KEYPAD_interface.h"  
#include"KEYPAD_config.h" 
#include"KEYPAD_private.h"

extern void KEYPAD_voidInit(void)

    {

    Keypad_u16State.KEYPAD_u16Switches = KEYPAD_u16UNPRESSED;

    Keypad_u16Bouncing_Flag.KEYPAD_u16Switches = KEYPAD_u16NOBOUNCING;

    return;
    }

extern Keypad_u16Switches KEYPAD_Keypad_u16SwitchesRead(void)
    {

    u8 local_u8Switch_Current_State;
    u8 local_u8SwitchIdx;
    u8 local_u8Switch_Last_State;
    u8 local_u8Bouncing_Flag;

    for (u8 Keypad_u8LoopCounter = 0; Keypad_u8LoopCounter < KEYPAD_u8NUM_ROWS; Keypad_u8LoopCounter++)
	{

	for (u8 Keypad_u8RowsCounter = 0; Keypad_u8RowsCounter < KEYPAD_u8NUM_ROWS; Keypad_u8RowsCounter++)
	    {

	    if (Keypad_u8RowsCounter == Keypad_u8LoopCounter)
		{

		DIO_u8WritePinVal(Keypad_u8RowS_Array[Keypad_u8RowsCounter], KEYPAD_u8PRESSEDSTATE);

		}
	    else
		{

		DIO_u8WritePinVal(Keypad_u8RowS_Array[Keypad_u8RowsCounter], !KEYPAD_u8PRESSEDSTATE);

		}
	    }

	for (u8 Keypad_u8ColumnsCounter = 0; Keypad_u8ColumnsCounter < KEYPAD_u8NUM_COLUMNS;
		Keypad_u8ColumnsCounter++)
	    {

	    local_u8SwitchIdx = Keypad_u8ColumnsCounter + (KEYPAD_u8NUM_ROWS * Keypad_u8LoopCounter);

	    /*Comment!: Read Switch value*/
	    DIO_u8ReadPinVal(Keypad_u8COLUMNS_Array[Keypad_u8ColumnsCounter], &local_u8Switch_Current_State);

	    /*Comment!: Read Switch's Last State*/
	    local_u8Switch_Last_State = GET_BIT(Keypad_u16State.KEYPAD_u16Switches, local_u8SwitchIdx);

	    /*Comment!: Read Switch Bouncing Flag*/
	    local_u8Bouncing_Flag = GET_BIT(Keypad_u16Bouncing_Flag.KEYPAD_u16Switches, local_u8SwitchIdx);


	    if (local_u8Bouncing_Flag == KEYPAD_u8FLAG_UP)

	  	    {
//	  	    DIO_u8WritePinVal(DIO_u8PIN7,DIO_u8HIGH);

	  	    /*Comment!: Check Last State For Switch*/
	  	    if (local_u8Switch_Current_State != KEYPAD_u8PRESSEDSTATE)
	  		{

	  		Keypad_u8Unpressed_Counter_Array[local_u8SwitchIdx]++;

	  		Keypad_u8pressed_Counter_Array[local_u8SwitchIdx] = 0;

	  		}

	  	    else if (local_u8Switch_Current_State == KEYPAD_u8PRESSEDSTATE)
	  		{

	  		Keypad_u8pressed_Counter_Array[local_u8SwitchIdx]++;

	  		Keypad_u8Unpressed_Counter_Array[local_u8SwitchIdx] = 0;

	  		}

	  	    else
	  		{

	  		}

	  	    /*Comment!: Check Any Counter reach the limit*/
	  	    if (Keypad_u8pressed_Counter_Array[local_u8SwitchIdx] == KEYPAD_u8COUNTER_LIMIT)

	  		{
	  		/*Comment!: Reset Pressed Counter*/
	  		Keypad_u8pressed_Counter_Array[local_u8SwitchIdx] = 0;

	  		/*Comment!: Make Bouncing Flag Low*/
	  		CLR_BIT(Keypad_u16Bouncing_Flag.KEYPAD_u16Switches, local_u8SwitchIdx);

	  		/*Comment!: Save Switch Statues as Pressed*/
	  		SET_BIT(Keypad_u16State.KEYPAD_u16Switches, local_u8SwitchIdx);

	  		}

	  	    else if(Keypad_u8Unpressed_Counter_Array[local_u8SwitchIdx] == KEYPAD_u8COUNTER_LIMIT)

	  		{
	  		/*Comment!: Reset UnPressed Counter*/
	  		Keypad_u8Unpressed_Counter_Array[local_u8SwitchIdx] = 0;

	  		/*Comment!: Make Bouncing Flag Low*/
	  		CLR_BIT(Keypad_u16Bouncing_Flag.KEYPAD_u16Switches, local_u8SwitchIdx);

	  		/*Comment!: Save Switch Statues as UnPressed*/
	  		CLR_BIT(Keypad_u16State.KEYPAD_u16Switches, local_u8SwitchIdx);

	  		}

	  	    else

	  		{

	  		}

	  	    }


	  	/*Comment!: Check if code is out of bouncing state*/
	  		else if (local_u8Bouncing_Flag != KEYPAD_u8FLAG_UP)
	  		    {

	  		  //  	    DIO_u8WritePinVal(DIO_u8PIN7,DIO_u8HIGH);

	  		    /*Comment!: Check Switch's Last state*/
	  		    switch (local_u8Switch_Last_State)
	  			{

	  		    case (!KEYPAD_u8SWITCH_PRESSED):

	  			    /*Comment!: Check if switch is pressed*/
	  			if (local_u8Switch_Current_State == KEYPAD_u8SWITCH_PRESSED)
	  			    {

	  			    /*Comment!: Rise Bouncing Flag*/
	  			    SET_BIT(Keypad_u16Bouncing_Flag.KEYPAD_u16Switches, local_u8SwitchIdx);

	  			    }

	  			else
	  			    {

	  			    }

	  			break;

	  		    case KEYPAD_u8SWITCH_PRESSED:

	  			    /*Comment!: Check if switch is UnPressed*/
	  			if (local_u8Switch_Current_State != KEYPAD_u8SWITCH_PRESSED)
	  			    {

	  			    /*Comment!: Rise Bouncing Flag*/
	  			    SET_BIT(Keypad_u16Bouncing_Flag.KEYPAD_u16Switches, local_u8SwitchIdx);

	  			    }

	  			else
	  			    {

	  			    }

	  			break;

	  		    default:

	  			break;

	  			}

	  		    }

	  		else
	  		    {

	  		    }

	  		}

	}

    return Keypad_u16State;
    }
