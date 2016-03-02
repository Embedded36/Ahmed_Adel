/*
 * main.c
 *
 *  Created on: Feb 24, 2016
 *      Author: Ahmed
 */
#include"../types.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include "../../HAL_LAYER/KEYPAD/KEYPAD_interface.h"

#define STARTING_POINT 0
#define SWITCH_PRESSED 1
#define CONTINOUS_MODE 2
#define CLICK_MODE  3
#define WAITING_FOR_SWITCH_RELEASE 4
#define TIME_LIMIT 10
#define LEFT 0
#define RIGHT 1
#define SH_CP     DIO_u8PIN24
#define ST_CP     DIO_u8PIN25
#define DS        DIO_u8PIN26
#define GET_BIT(Reg,Bit_no)                   (((Reg)>>(Bit_no))&1)

int main()
    {

    Keypad_u16Switches keypad;
    DIO_voidInit();

    KEYPAD_voidInit();
    DIO_u8WritePortDir(1, 0xff);
    DIO_u8WritePortDir(3, 0xff);

    while (1)
	{
	keypad = KEYPAD_Keypad_u16SwitchesRead();

	DIO_u8WritePortVal(1,keypad.KEYPAD_u16Switches );
	DIO_u8WritePortVal(3, keypad.KEYPAD_u16Switches>>8);
//            if(keypad.KEYPAD_u16Switches==0)
//        	{
//        	DIO_u8WritePinVal(DIO_u8PIN31,DIO_u8HIGH);
//        	}
//            else
//        	{
//        	DIO_u8WritePinVal(DIO_u8PIN31,DIO_u8LOW);
//        	}
//break;
	}
//    u8 local_u8state = STARTING_POINT;
//    u8 local_u8SwitchRead;
//    u16 local_u16Counter;
//    u8 local_Direction_Flag = RIGHT;
//
//    u8 local_u8MotorPin1Val[2] =
//	{
//	DIO_u8HIGH, DIO_u8LOW
//	};
//    u8 LOCAL_U8NAMEMATRIX[2][8] =
//	{
//	    {
//	    0b00111100, 0b01111110, 0b11000011, 0b11000011, 0b11111111, 0b11111111, 0b11000011, 0b11000011
//	    },
//	    {
//	    0b11000011, 0b11000011, 0b11000011, 0b11111111, 0b11111111, 0b11000011, 0b11000011, 0b11000011
//	    },
//	};
//
//    DIO_voidInit();
//
//    TACTILE_SWITCH_voidInit();
//
//    while (1)
//
//	{
//
//	TACTILE_SWITCH_u8Read(TACTILE_SWITCH_u8SWITCH1ID, &local_u8SwitchRead);
//
//	/*Comment!:Display at Dot Matrix */
//		for (u8 j = 0; j < 8; j++)
//		    {
//
//		    DIO_u8WritePinVal(SH_CP, DIO_u8LOW);
//		    DIO_u8WritePinVal(ST_CP, DIO_u8LOW);
//
//		   for (u8 a = 0; a < 8; a++)
//			{
//
//			if (a != j)
//			    {
//			    DIO_u8WritePinVal(DS,
//			    DIO_u8HIGH);
//			    }
//			else
//			    {
//			    DIO_u8WritePinVal(DS,
//			    DIO_u8LOW);
//			    }
//			DIO_u8WritePinVal(SH_CP, DIO_u8HIGH);
//			DIO_u8WritePinVal(SH_CP, DIO_u8LOW);
//			}
//
//
//
//		    for (u8 i = 0; i < 8; i++)
//			{
//			DIO_u8WritePinVal(DS, GET_BIT(LOCAL_U8NAMEMATRIX[local_Direction_Flag][j], i));
//			DIO_u8WritePinVal(SH_CP, DIO_u8HIGH);
//			DIO_u8WritePinVal(SH_CP, DIO_u8LOW);
//			}
//
//		    DIO_u8WritePinVal(ST_CP, DIO_u8HIGH);
//
//		    }
//
//		    /*comment!: end of displaying at dot matrix*/
//
//
//	    switch (local_u8state)
//
//		{
//
//	    case STARTING_POINT:
//
//		if (local_u8SwitchRead == TACTILE_SWITCH_u8PRESSED)
//		    {
//		    DIO_u8WritePinVal(DIO_u8PIN8, local_u8MotorPin1Val[local_Direction_Flag]);
//
//		    DIO_u8WritePinVal(DIO_u8PIN9, !local_u8MotorPin1Val[local_Direction_Flag]);
//
//		    local_u8state = SWITCH_PRESSED;
//
//		    local_u16Counter = 0;
//		    }
//
//		else if (local_u8SwitchRead != TACTILE_SWITCH_u8PRESSED)
//		    {
//
//		    DIO_u8WritePinVal(DIO_u8PIN8, DIO_u8HIGH);
//
//		    DIO_u8WritePinVal(DIO_u8PIN9, DIO_u8HIGH);
//
//		    }
//
//		else
//		    {
//
//		    }
//
//		break;
//
//	    case SWITCH_PRESSED:
//
//		local_u16Counter++;
//
//		if (local_u8SwitchRead != TACTILE_SWITCH_u8PRESSED)
//		    {
//
//		    if (local_u16Counter <= TIME_LIMIT)
//
//			{
//			local_u8state = CONTINOUS_MODE;
//			}
//		    else
//			{
//
//			local_Direction_Flag = !local_Direction_Flag;
//
//			local_u8state = STARTING_POINT;
//			}
//
//		    }
//
//		else
//		    {
//
//		    }
//
//		break;
//
//	    case CONTINOUS_MODE:
//
//		DIO_u8WritePinVal(DIO_u8PIN8, local_u8MotorPin1Val[local_Direction_Flag]);
//
//		DIO_u8WritePinVal(DIO_u8PIN9, !local_u8MotorPin1Val[local_Direction_Flag]);
//
//		if (local_u8SwitchRead == TACTILE_SWITCH_u8PRESSED)
//		    {
//
//		    DIO_u8WritePinVal(DIO_u8PIN8, DIO_u8HIGH);
//
//		    DIO_u8WritePinVal(DIO_u8PIN9, DIO_u8HIGH);
//
//		    local_u8state = WAITING_FOR_SWITCH_RELEASE;
//
//		    }
//
//		else
//		    {
//
//		    }
//
//		break;
//
//	    case WAITING_FOR_SWITCH_RELEASE:
//
//		if (local_u8SwitchRead != TACTILE_SWITCH_u8PRESSED)
//		    {
//
//		    local_u8state = STARTING_POINT;
//
//		    }
//
//		else
//		    {
//
//		    }
//		break;
//
//	    default:
//
//		break;
//
//		}
//
//	    }

    return 0;
    }

