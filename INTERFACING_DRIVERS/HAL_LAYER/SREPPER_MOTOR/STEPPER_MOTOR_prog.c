#include"../../Shared_Libraries/types.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include"STEPPER_MOTOR_interface.h"  
#include"STEPPER_MOTOR_config.h" 
#include"STEPPER_MOTOR_private.h"

/*******************************************************/
/**************** Private Definitions ******************/
/*******************************************************/

/*Comment!: Motor state*/
  static u8 STEPPER_MOTOR_u8State=1;

  /*******************************************************/
  /********************* Functions ***********************/
  /*******************************************************/
void STEPPER_MOTOR_voidInit(void)
    {
    return;
    }

void STEPPER_MOTOR_RotateRight(void)
    {

    /*Comment!: check for rotation sequence overflow */
    if (STEPPER_MOTOR_u8State == 1)
	{
	STEPPER_MOTOR_u8State = 0x08;
	}
    else
	{
	STEPPER_MOTOR_u8State >>= 1;
	}

    /*Comment!: write rotation sequence to DIO pins */
    DIO_u8WritePinVal(STEPPER_MOTOR_u8PIN0, GET_BIT(STEPPER_MOTOR_u8State, 0));
    DIO_u8WritePinVal(STEPPER_MOTOR_u8PIN1, GET_BIT(STEPPER_MOTOR_u8State, 1));
    DIO_u8WritePinVal(STEPPER_MOTOR_u8PIN2, GET_BIT(STEPPER_MOTOR_u8State, 2));
    DIO_u8WritePinVal(STEPPER_MOTOR_u8PIN3, GET_BIT(STEPPER_MOTOR_u8State, 3));

    return;
    }

void STEPPER_MOTOR_RotateLeft(void)
    {

    /*Comment!: check for rotation sequence overflow */
    if (STEPPER_MOTOR_u8State == 0x08)
	{
	STEPPER_MOTOR_u8State = 0x01;
	}
    else
	{
	STEPPER_MOTOR_u8State <<= 1;
	}

    /*Comment!: write rotation sequence to DIO pins */
    DIO_u8WritePinVal(STEPPER_MOTOR_u8PIN0, GET_BIT(STEPPER_MOTOR_u8State, 0));
    DIO_u8WritePinVal(STEPPER_MOTOR_u8PIN1, GET_BIT(STEPPER_MOTOR_u8State, 1));
    DIO_u8WritePinVal(STEPPER_MOTOR_u8PIN2, GET_BIT(STEPPER_MOTOR_u8State, 2));
    DIO_u8WritePinVal(STEPPER_MOTOR_u8PIN3, GET_BIT(STEPPER_MOTOR_u8State, 3));

    return;
    }
