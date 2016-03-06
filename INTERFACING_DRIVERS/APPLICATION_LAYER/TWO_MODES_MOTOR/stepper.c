///*
// * main.c
// *
// *  Created on: Feb 24, 2016
// *      Author: Ahmed
// */
//#include"../types.h"
//#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
//#include "../../HAL_LAYER/TACTILE_SWITCH/TACTILE_SWITCH_interface.h"
//#include"../../HAL_LAYER/KEYPAD/KEYPAD_interface.h"
//
//#define DIO_u8PORTC   ((volatile u8*)(0x35))
//#define STEPPER_COUNTER_LIMIT 100
//#define STARTING_POINT 0
//#define SWITCH_PRESSED 1
//#define CONTINOUS_MODE 2
//#define CLICK_MODE  3
//#define WAITING_FOR_SWITCH_RELEASE 4
//#define TIME_LIMIT 10
//#define LEFT 0
//#define RIGHT 1
//#define OFF 2
//#define SH_CP     DIO_u8PIN24
//#define ST_CP     DIO_u8PIN25
//#define DS        DIO_u8PIN26
//#define GET_BIT(Reg,Bit_no)                   (((Reg)>>(Bit_no))&1)
//
//void stepper(void)
//    {
//
//    static u8 loop = 1;
//
//    loop <<= 1;
//    if (loop == 16)
//	{
//	loop = 1;
//	}
//
//    DIO_u8WritePinVal(10, GET_BIT(loop, 0));
//    DIO_u8WritePinVal(11, GET_BIT(loop, 1));
//    DIO_u8WritePinVal(12, GET_BIT(loop, 2));
//    DIO_u8WritePinVal(13, GET_BIT(loop, 3));
//
//    }
//
//int main()
//    {
//
//    u8 local_u8state = STARTING_POINT;
//    u8 local_u8SwitchRead;
//    u16 local_u16Counter;
//    u8 local_Direction_Flag = RIGHT;
//    u16 local_stepper_counter = 0;
//    Keypad_u16Switches keypad;
//    u8 local_Display_Flag = OFF;
//    u8 local_u8MotorPin1Val[2] =
//	{
//	DIO_u8HIGH, DIO_u8LOW
//	};
//    u8 LOCAL_U8NAMEMATRIX[3][8] =
//	{
//	    {
//	    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7C
//	    },
//	    {
//	    0x78, 0x44, 0x48, 0x70, 0x70, 0x48, 0x44, 0x42
//	    },
//	    {
//	    0, 0, 0, 0, 0, 0, 0, 0
//	    }
//	};
//
//    DIO_voidInit();
//
//    TACTILE_SWITCH_voidInit();
//
//  KEYPAD_voidInit();
//
//    *DIO_u8PORTC = 0x0f;
//
//    while (1)
//
//	{
//
////	keypad = KEYPAD_Keypad_u16SwitchesRead();
////
//////	local_stepper_counter++;
//////(keypad.KEYPAD_u16Switches * STEPPER_COUNTER_LIMIT)
////	if (keypad.KEYPAD_u16Switches )
////	    {
////	    stepper();
////	    //local_stepper_counter = 0;
////	    }
//
//	TACTILE_SWITCH_u8Read(TACTILE_SWITCH_u8SWITCH1ID, &local_u8SwitchRead);
//
//	/*Comment!:Display at Dot Matrix */
//	for (u8 j = 0; j < 8; j++)
//	    {
//
//	    DIO_u8WritePinVal(SH_CP, DIO_u8LOW);
//	    DIO_u8WritePinVal(ST_CP, DIO_u8LOW);
//
//	    for (u8 a = 0; a < 8; a++)
//		{
//
//		if (a != j)
//		    {
//		    DIO_u8WritePinVal(DS,
//		    DIO_u8HIGH);
//		    }
//		else
//		    {
//		    DIO_u8WritePinVal(DS,
//		    DIO_u8LOW);
//		    }
//		DIO_u8WritePinVal(SH_CP, DIO_u8HIGH);
//		DIO_u8WritePinVal(SH_CP, DIO_u8LOW);
//		}
//
//	    for (u8 i = 0; i < 8; i++)
//		{
//		DIO_u8WritePinVal(DS, GET_BIT(LOCAL_U8NAMEMATRIX[local_Display_Flag][j], i));
//		DIO_u8WritePinVal(SH_CP, DIO_u8HIGH);
//		DIO_u8WritePinVal(SH_CP, DIO_u8LOW);
//		}
//
//	    DIO_u8WritePinVal(ST_CP, DIO_u8HIGH);
//
//	    }
//
//	/*comment!: end of displaying at dot matrix*/
//
//	switch (local_u8state)
//
//	    {
//
//	case STARTING_POINT:
//
//	    local_Display_Flag = OFF;
//
//	    if (local_u8SwitchRead == TACTILE_SWITCH_u8PRESSED)
//		{
//		DIO_u8WritePinVal(DIO_u8PIN8, local_u8MotorPin1Val[local_Direction_Flag]);
//
//		DIO_u8WritePinVal(DIO_u8PIN9, !local_u8MotorPin1Val[local_Direction_Flag]);
//
//		local_u8state = SWITCH_PRESSED;
//
//		local_u16Counter = 0;
//
//		local_Display_Flag = local_Direction_Flag;
//
//		}
//
//	    else if (local_u8SwitchRead != TACTILE_SWITCH_u8PRESSED)
//		{
//
//		DIO_u8WritePinVal(DIO_u8PIN8, DIO_u8HIGH);
//
//		DIO_u8WritePinVal(DIO_u8PIN9, DIO_u8HIGH);
//
//		}
//
//	    else
//		{
//
//		}
//
//	    break;
//
//	case SWITCH_PRESSED:
//
//	    local_u16Counter++;
//
//	    if (local_u8SwitchRead != TACTILE_SWITCH_u8PRESSED)
//		{
//
//		if (local_u16Counter <= TIME_LIMIT)
//
//		    {
//		    local_u8state = CONTINOUS_MODE;
//		    }
//		else
//		    {
//
//		    local_Direction_Flag = !local_Direction_Flag;
//
//		    local_u8state = STARTING_POINT;
//		    }
//
//		}
//
//	    else
//		{
//
//		}
//
//	    break;
//
//	case CONTINOUS_MODE:
//
//	    DIO_u8WritePinVal(DIO_u8PIN8, local_u8MotorPin1Val[local_Direction_Flag]);
//
//	    DIO_u8WritePinVal(DIO_u8PIN9, !local_u8MotorPin1Val[local_Direction_Flag]);
//
//	    if (local_u8SwitchRead == TACTILE_SWITCH_u8PRESSED)
//		{
//
//		DIO_u8WritePinVal(DIO_u8PIN8, DIO_u8HIGH);
//
//		DIO_u8WritePinVal(DIO_u8PIN9, DIO_u8HIGH);
//
//		local_Display_Flag = OFF;
//
//		local_u8state = WAITING_FOR_SWITCH_RELEASE;
//
//		}
//
//	    else
//		{
//
//		}
//
//	    break;
//
//	case WAITING_FOR_SWITCH_RELEASE:
//
//	    if (local_u8SwitchRead != TACTILE_SWITCH_u8PRESSED)
//		{
//
//		local_u8state = STARTING_POINT;
//
//		}
//
//	    else
//		{
//
//		}
//	    break;
//
//	default:
//
//	    break;
//
//	    }
//
//	}
//
//    return 0;
//    }

/*
 * main.c
 *
 *  Created on: Feb 24, 2016
 *      Author: Ahmed
 */
#include"../types.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include "../../HAL_LAYER/TACTILE_SWITCH/TACTILE_SWITCH_interface.h"
#include"../../HAL_LAYER/KEYPAD/KEYPAD_interface.h"


#define DIO_u8PORTC   ((volatile u8*)(0x35))
#define STARTING_POINT 0
#define SWITCH_PRESSED 1
#define CONTINOUS_MODE 2
#define CLICK_MODE  3
#define WAITING_FOR_SWITCH_RELEASE 4
#define TIME_LIMIT 70
#define LEFT 0
#define RIGHT 1
#define SH_CP     DIO_u8PIN24
#define ST_CP     DIO_u8PIN25
#define DS        DIO_u8PIN26
#define DISPLAY_RIGHT 0
#define DISPLAY_LEFT 1
#define DISPLAY_OFF 2
#define GET_BIT(Reg,Bit_no)                   (((Reg)>>(Bit_no))&1)

void stepper(void)
    {

    static u8 loop = 1;

    loop <<= 1;
    if (loop == 16)
	{
	loop = 1;
	}

    DIO_u8WritePinVal(10, GET_BIT(loop, 0));
    DIO_u8WritePinVal(11, GET_BIT(loop, 1));
    DIO_u8WritePinVal(12, GET_BIT(loop, 2));
    DIO_u8WritePinVal(13, GET_BIT(loop, 3));

    }

int main()
    {

    u8 local_u8state = STARTING_POINT;
    u8 local_u8SwitchRead;
    u16 local_u16Counter;
    u8 local_Direction_Flag = RIGHT;
    u8 local_Display_Flag = DISPLAY_OFF;
    Keypad_u16Switches keypad;
    u8 local_u8MotorPin1Val[2] =
	{
	DIO_u8HIGH, DIO_u8LOW
	};
    u8 LOCAL_U8NAMEMATRIX[3][8] =
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

    DIO_voidInit();

    TACTILE_SWITCH_voidInit();

    KEYPAD_voidInit();

    *DIO_u8PORTC = 0x0f;

    while (1)

	{

	TACTILE_SWITCH_u8Read(TACTILE_SWITCH_u8SWITCH1ID, &local_u8SwitchRead);

	/*Comment!:Display at Dot Matrix */
	for (u8 j = 0; j < 8; j++)
	    {

	    DIO_u8WritePinVal(SH_CP, DIO_u8LOW);
	    DIO_u8WritePinVal(ST_CP, DIO_u8LOW);

	    for (u8 a = 0; a < 8; a++)
		{

		if (a != j)
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

	    for (u8 i = 0; i < 8; i++)
		{
		DIO_u8WritePinVal(DS, GET_BIT(LOCAL_U8NAMEMATRIX[local_Display_Flag][j], i));
		DIO_u8WritePinVal(SH_CP, DIO_u8HIGH);
		DIO_u8WritePinVal(SH_CP, DIO_u8LOW);
		}

	    DIO_u8WritePinVal(ST_CP, DIO_u8HIGH);

	    //////////start of switch

	    	keypad = KEYPAD_Keypad_u16SwitchesRead();

	    	if (keypad.KEYPAD_u16Switches == 1 )
	    		    {
	    		    stepper();
	    		    //local_stepper_counter = 0;
	    		    }

	    	switch (local_u8state)

		{

	    case STARTING_POINT:

		if (local_u8SwitchRead == TACTILE_SWITCH_u8PRESSED)
		    {
		    DIO_u8WritePinVal(DIO_u8PIN8, local_u8MotorPin1Val[local_Direction_Flag]);

		    DIO_u8WritePinVal(DIO_u8PIN9, !local_u8MotorPin1Val[local_Direction_Flag]);

		    local_u8state = SWITCH_PRESSED;

		    local_Display_Flag = local_Direction_Flag;

		    local_u16Counter = 0;
		    }

		else if (local_u8SwitchRead != TACTILE_SWITCH_u8PRESSED)
		    {

		    DIO_u8WritePinVal(DIO_u8PIN8, DIO_u8HIGH);

		    DIO_u8WritePinVal(DIO_u8PIN9, DIO_u8HIGH);

		    local_Display_Flag = DISPLAY_OFF;
		    }

		else
		    {

		    }

		break;

	    case SWITCH_PRESSED:

		local_u16Counter++;

		if (local_u8SwitchRead != TACTILE_SWITCH_u8PRESSED)
		    {

		    if (local_u16Counter <= TIME_LIMIT)

			{
			local_u8state = CONTINOUS_MODE;
			}
		    else
			{

			local_Direction_Flag = !local_Direction_Flag;

			local_u8state = STARTING_POINT;
			}

		    }

		else
		    {

		    }

		break;

	    case CONTINOUS_MODE:

		DIO_u8WritePinVal(DIO_u8PIN8, local_u8MotorPin1Val[local_Direction_Flag]);

		DIO_u8WritePinVal(DIO_u8PIN9, !local_u8MotorPin1Val[local_Direction_Flag]);

		if (local_u8SwitchRead == TACTILE_SWITCH_u8PRESSED)
		    {

		    DIO_u8WritePinVal(DIO_u8PIN8, DIO_u8HIGH);

		    DIO_u8WritePinVal(DIO_u8PIN9, DIO_u8HIGH);

		    local_u8state = WAITING_FOR_SWITCH_RELEASE;

		    }

		else
		    {

		    }

		break;

	    case WAITING_FOR_SWITCH_RELEASE:

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

	/*comment!: end of displaying at dot matrix*/

	}

    return 0;
    }

