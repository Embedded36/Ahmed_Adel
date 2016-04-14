#include"../../Shared_Libraries/types.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include"KEYPAD_interface.h"  
#include"KEYPAD_config.h" 
#include"KEYPAD_private.h"

/******************************************************/
/********************** Arrays ************************/
/******************************************************/

/*Comment!: mapping to DIO pins of rows and columns*/
const u8 Keypad_u8RowS_Array[KEYPAD_u8NUM_ROWS] =
    {
    KEYPAD_u8ROW1, KEYPAD_u8ROW2, KEYPAD_u8ROW3, KEYPAD_u8ROW4
    };

const u8 Keypad_u8COLUMNS_Array[KEYPAD_u8NUM_COLUMNS] =
    {
    KEYPAD_u8COLUMN1, KEYPAD_u8COLUMN2, KEYPAD_u8COLUMN3, KEYPAD_u8COLUMN4
    };

/******************************************************/
/********************* Functions **********************/
/******************************************************/

extern void KEYPAD_voidInit(void)
    {

    return;
    }

extern Keypad_u16Switches KEYPAD_Keypad_u16SwitchesRead(void)
    {

    u8 local_u8Switch_Current_State;
    u8 local_u8SwitchIdx;
    Keypad_u16Switches Keypad_u16State;

    /*Comment!: Initialize Switches as unPressed */
    Keypad_u16State.KEYPAD_u16Switches = KEYPAD_u16UNPRESSED;

    /*Comment!: Loop over all rows*/
    for (u8 Keypad_u8LoopCounter = 0; Keypad_u8LoopCounter < KEYPAD_u8NUM_ROWS; Keypad_u8LoopCounter++)
	{

	/*Comment!: make one output as pressed state and other outputs as released state */
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

	    /*Comment!: Get Switch Index  */
	    /*Comment!: Switch Index from 0~15*/
	    local_u8SwitchIdx = Keypad_u8ColumnsCounter + (KEYPAD_u8NUM_ROWS * Keypad_u8LoopCounter);

	    /*Comment!: Read Switch value*/
	    DIO_u8ReadPinVal(Keypad_u8COLUMNS_Array[Keypad_u8ColumnsCounter], &local_u8Switch_Current_State);

	    if (local_u8Switch_Current_State == KEYPAD_u8PRESSEDSTATE)
		{

		SET_BIT(Keypad_u16State.KEYPAD_u16Switches, local_u8SwitchIdx);

		}
	    else
		{

		CLR_BIT(Keypad_u16State.KEYPAD_u16Switches, local_u8SwitchIdx);

		}

	    }

	}

    return Keypad_u16State;
    }
