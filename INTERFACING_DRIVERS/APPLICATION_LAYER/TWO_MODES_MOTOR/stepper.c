#include"../../Shared_Libraries/types.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include "../../HAL_LAYER/TACTILE_SWITCH/TACTILE_SWITCH_interface.h"
#include"../../HAL_LAYER/KEYPAD/KEYPAD_interface.h"

#define DIO_u8PORTC        ((volatile u8*)(0x35))
#define STARTING_POINT             0
#define SWITCH_PRESSED             1
#define CONTINOUS_MODE             2
#define CLICK_MODE                 3
#define WAITING_FOR_SWITCH_RELEASE 4
#define TIME_LIMIT                 50
#define LEFT                       0
#define RIGHT                      1
#define SH_CP                      DIO_u8PIN24
#define ST_CP                      DIO_u8PIN25
#define DS                         DIO_u8PIN26
#define DISPLAY_RIGHT              0
#define DISPLAY_LEFT               1
#define DISPLAY_OFF                2
#define STOP_SWITCH_INDEX          3
#define GET_BIT(Reg,Bit_no)        (((Reg)>>(Bit_no))&1)

/*Comment!:Rotate Stepper motor one step */
void Stepper_voidRotate(void);

/*Comment!:return index of pressed switch  */
/*Range!:1~16 */
u8 Stepper_16_Switch_Number(u16 Copy_u16KeypadState);

int main()
    {

    u8 local_u8state = STARTING_POINT;
    u8 local_u8SwitchRead;
    u16 local_u16Counter;
    u8 local_Direction_Flag = RIGHT;
    u16 local_stepper_counter = 0;
    u8 local_Display_Flag = DISPLAY_OFF;
    Keypad_u16Switches keypad;
    u8 local_u8Switch_Pressed_num = STOP_SWITCH_INDEX;
    u8 local_u8MotorPin1Val[2] =
	{
	DIO_u8HIGH, DIO_u8LOW
	};
    u8 LOCAL_U8DirectionMATRIX[3][8] =
	{
	    {
	    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7C
	    },
	    {
	    0x78, 0x44, 0x48, 0x70, 0x70, 0x48, 0x44, 0x42
	    },
	    {
	    0, 0, 0, 0, 0, 0, 0, 0
	    }
	};

    /*Comment!:calling initialization functions */
    DIO_voidInit();

    TACTILE_SWITCH_voidInit();

    KEYPAD_voidInit();

    /*Comment!: use pull up resistors on portc*/
    /*Comment!: this is against design rules but i had to use this way because there weren't pull up resistors on hardware*/
    *DIO_u8PORTC = 0x0f;

    /*Comment!:shift register work at rising edge so sh,st must be low before writing to shift register  */
    DIO_u8WritePinVal(SH_CP, DIO_u8LOW);
    DIO_u8WritePinVal(ST_CP, DIO_u8LOW);

    while (1)

	{

	/*Comment!:Display at Dot Matrix */
	for (u8 local_u8RowsLoopCounter = 0; local_u8RowsLoopCounter < 8; local_u8RowsLoopCounter++)
	    {

	    /*Comment!:active one row each time */
	    for (u8 local_u8RowIndex = 0; local_u8RowIndex < 8; local_u8RowIndex++)
		{

		/*Comment!:write bit to shift register */
		if (local_u8RowIndex != local_u8RowsLoopCounter)
		    {
		    DIO_u8WritePinVal(DS,
		    DIO_u8HIGH);
		    }
		else
		    {
		    DIO_u8WritePinVal(DS,
		    DIO_u8LOW);
		    }

		DIO_u8WritePinVal(SH_CP, DIO_u8HIGH);
		DIO_u8WritePinVal(SH_CP, DIO_u8LOW);

		}

	    /*Comment!:Write column  */
	    for (u8 local_u8ColumnsLoopCounter = 0; local_u8ColumnsLoopCounter < 8; local_u8ColumnsLoopCounter++)
		{

		/*Comment!:write bit to shift register */
		DIO_u8WritePinVal(DS,
			GET_BIT(LOCAL_U8DirectionMATRIX[local_Display_Flag][local_u8RowsLoopCounter],
				local_u8ColumnsLoopCounter));

		DIO_u8WritePinVal(SH_CP, DIO_u8HIGH);
		DIO_u8WritePinVal(SH_CP, DIO_u8LOW);

		}

	    /*Comment!:latch Rows and Columns to dot matrix */
	    DIO_u8WritePinVal(ST_CP, DIO_u8HIGH);
	    DIO_u8WritePinVal(ST_CP, DIO_u8LOW);

	    }

	/*comment!: end of displaying one column*/

	/*Comment!:read Keypad*/
	keypad = KEYPAD_Keypad_u16SwitchesRead();

	/*Comment!:Check if switch pressed */
	if (keypad.KEYPAD_u16Switches)
	    {
	    /*Comment!:get number of pressed switch */
	    local_u8Switch_Pressed_num = Stepper_16_Switch_Number(keypad.KEYPAD_u16Switches);

	    }
	else
	    {

	    }

	if ((local_u8Switch_Pressed_num < local_stepper_counter) && local_u8Switch_Pressed_num != STOP_SWITCH_INDEX)

	    {

	    Stepper_voidRotate();

	    local_stepper_counter = 0;

	    }
	else if (local_u8Switch_Pressed_num != STOP_SWITCH_INDEX)
	    {

	    local_stepper_counter++;

	    }
	else
	    {

	    }

	/*Comment!:read switch */
	TACTILE_SWITCH_u8Read(TACTILE_SWITCH_u8SWITCH1ID, &local_u8SwitchRead);

	switch (local_u8state)

	    {

	case STARTING_POINT:

	    if (local_u8SwitchRead == TACTILE_SWITCH_u8PRESSED)
		{
		/*Comment!:Rotate Motor */
		DIO_u8WritePinVal(DIO_u8PIN8, local_u8MotorPin1Val[local_Direction_Flag]);

		DIO_u8WritePinVal(DIO_u8PIN9, !local_u8MotorPin1Val[local_Direction_Flag]);

		/*Comment!:Change State */
		local_u8state = SWITCH_PRESSED;

		/*Comment!:Change direction at display */
		local_Display_Flag = local_Direction_Flag;

		/*Comment!:Reset Time Counter */
		local_u16Counter = 0;
		}

	    else if (local_u8SwitchRead != TACTILE_SWITCH_u8PRESSED)
		{

		/*Comment!:Stop motor */
		DIO_u8WritePinVal(DIO_u8PIN8, DIO_u8HIGH);

		DIO_u8WritePinVal(DIO_u8PIN9, DIO_u8HIGH);

		/*Comment!:Turn off dot matrix*/
		local_Display_Flag = DISPLAY_OFF;
		}

	    else
		{

		}

	    break;

	case SWITCH_PRESSED:

	    /*Comment!:increment counter that represents time */
	    local_u16Counter++;

	    if (local_u8SwitchRead != TACTILE_SWITCH_u8PRESSED)
		{

		/*Comment!:Checking time */
		if (local_u16Counter <= TIME_LIMIT)

		    {

		    /*Comment!:change state*/
		    local_u8state = CONTINOUS_MODE;

		    }

		else
		    {

		    /*Comment!:Change direction*/
		    local_Direction_Flag = !local_Direction_Flag;

		    /*Comment!:change state*/
		    local_u8state = STARTING_POINT;
		    }

		}

	    else
		{

		}

	    break;

	case CONTINOUS_MODE:

	    /*Comment!:Rotate Motor*/
	    DIO_u8WritePinVal(DIO_u8PIN8, local_u8MotorPin1Val[local_Direction_Flag]);

	    DIO_u8WritePinVal(DIO_u8PIN9, !local_u8MotorPin1Val[local_Direction_Flag]);

	    if (local_u8SwitchRead == TACTILE_SWITCH_u8PRESSED)
		{
		/*Comment!:stop motor*/
		DIO_u8WritePinVal(DIO_u8PIN8, DIO_u8HIGH);

		DIO_u8WritePinVal(DIO_u8PIN9, DIO_u8HIGH);

		/*Comment!:change state*/
		local_u8state = WAITING_FOR_SWITCH_RELEASE;

		}

	    else
		{

		}

	    break;

	case WAITING_FOR_SWITCH_RELEASE:

	    /*Comment!:waiting for switch release*/
	    if (local_u8SwitchRead != TACTILE_SWITCH_u8PRESSED)
		{

		local_u8state = STARTING_POINT;

		}

	    else
		{

		}
	    break;

	default:

	    break;

	    }

	}

    return 0;
    }

u8 Stepper_16_Switch_Number(u16 Copy_u16KeypadState)
    {

    u8 local_u8Switch_Pressed_num;

    for (u8 local_u8LoopCounter = 0; local_u8LoopCounter < 16; local_u8LoopCounter++)
	{

	if ((1 << local_u8LoopCounter) == Copy_u16KeypadState)
	    {
	    local_u8Switch_Pressed_num = local_u8LoopCounter + 1;
	    }

	else
	    {

	    }

	}
    return local_u8Switch_Pressed_num;
    }

void Stepper_voidRotate(void)
    {

    static u8 local_u8loop = 1;

    local_u8loop <<= 1;

    if (local_u8loop == 16)
	{

	local_u8loop = 1;

	}

    DIO_u8WritePinVal(10, GET_BIT(local_u8loop, 0));
    DIO_u8WritePinVal(11, GET_BIT(local_u8loop, 1));
    DIO_u8WritePinVal(12, GET_BIT(local_u8loop, 2));
    DIO_u8WritePinVal(13, GET_BIT(local_u8loop, 3));

    }
