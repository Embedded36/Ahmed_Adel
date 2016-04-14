#include"../../Shared_Libraries/types.h"
#include"DIO_interface.h"
#include"DIO_config.h"
#include"DIO_private.h"

/*******************************************************/
/******************* Arrays Of Ports *******************/
/*******************************************************/
static volatile u8* OUTPUT_PORTS_ARRAY[4] =
{ DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD };
static volatile u8* INPUT_PORTS_ARRAY[4] =
{ DIO_u8PINA, DIO_u8PINB, DIO_u8PINC, DIO_u8PIND };
static volatile u8* DIRECTION_PORTS_ARRAY[4] =
{ DIO_u8DDRA, DIO_u8DDRB, DIO_u8DDRC, DIO_u8DDRD };

/*******************************************************/
/*********************** Functions *********************/
/*******************************************************/
extern u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx, u8* Copy_u8PtrToVal)
    {
    u8 local_u8PortNumber;
    u8 local_u8PinNumber;
    u8 local_u8ErrorFlag;
    u8 local_u8PinValue;
    u8 local_u8PinDir;

    /*Comment!: Read Pin Direction*/
    DIO_u8ReadPinDir(Copy_u8PinIdx, &local_u8PinDir);

    /*Comment!: Check Pin Direction*/
    if (local_u8PinDir == DIO_u8INPUT)
	{

	/*Comment!: local_u8PortNumber=Copy_u8PinIdx/8 */
	local_u8PortNumber = Copy_u8PinIdx >> DIO_DEVIED_BY_EIGHT;

	/*Comment!: Getting pin number in port */
	local_u8PinNumber = Copy_u8PinIdx % DIO_u8PINS_PER_PORT;

	/*Comment!: Check pin index in range or out of range*/
	if (local_u8PortNumber < DIO_u8NUM_OF_PORTS)
	    {
	    /*Comment!: Get bit value then return its value */
	    local_u8PinValue = GET_BIT(*INPUT_PORTS_ARRAY[local_u8PortNumber],
		    local_u8PinNumber);

	    *Copy_u8PtrToVal = local_u8PinValue;

	    local_u8ErrorFlag = ok;
	    }

	else
	    {
	    local_u8ErrorFlag = error;
	    }

	}

    else
	{
	local_u8ErrorFlag = error;
	}

    return local_u8ErrorFlag;

    }

extern u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx, u8 Copy_u8PinVal)
    {
    u8 local_u8PortNumber;
    u8 local_u8PinNumber;
    u8 local_u8ErrorFlag;
    u8 local_u8PinDir;

    /*Comment!: Read Pin Direction*/
    DIO_u8ReadPinDir(Copy_u8PinIdx, &local_u8PinDir);

    /*Comment!: Check Pin Direction*/
    if (local_u8PinDir == DIO_u8OUTPUT)
	{
	/*Comment!: local_u8PortNumber=Copy_u8PinIdx/8 */
	local_u8PortNumber = Copy_u8PinIdx >> DIO_DEVIED_BY_EIGHT;

	/*Comment!: Getting pin number in port */
	local_u8PinNumber = Copy_u8PinIdx % DIO_u8PINS_PER_PORT;

	/*Comment!: Check pin index in range or out of range */
	if (local_u8PortNumber < DIO_u8NUM_OF_PORTS)
	    {
	    /*Comment!: Write pin value */
	    WRITE_BIT(*OUTPUT_PORTS_ARRAY[local_u8PortNumber],
		    local_u8PinNumber, Copy_u8PinVal);

	    local_u8ErrorFlag = ok;
	    }
	else
	    {
	    local_u8ErrorFlag = error;
	    }
	}

    else
	{
	local_u8ErrorFlag = error;
	}

    return local_u8ErrorFlag;
    }

extern u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx, u8* Copy_u8PtrToVal)
    {
    u8 local_u8ErrorFlag;

    /*Comment!: Check port index in range or out of range*/
    if (Copy_u8PortIdx < DIO_u8NUM_OF_PORTS)
	{

	/*Comment!: Read port value */
	*Copy_u8PtrToVal = *INPUT_PORTS_ARRAY[Copy_u8PortIdx];

	local_u8ErrorFlag = ok;
	}

    else
	{
	local_u8ErrorFlag = error;
	}

    return local_u8ErrorFlag;
    }

extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx, u8 Copy_u8PortVal)
    {
    u8 local_u8ErrorFlag;

    /*Comment!: Check port index in range or out of range */
    if (Copy_u8PortIdx < DIO_u8NUM_OF_PORTS)
	{
	/*Comment!: Write port value */
	*OUTPUT_PORTS_ARRAY[Copy_u8PortIdx] = Copy_u8PortVal;

	local_u8ErrorFlag = ok;
	}

    else
	{
	local_u8ErrorFlag = error;
	}

    return local_u8ErrorFlag;
    }

extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx, u8 Copy_u8PinDir)
    {
    u8 local_u8PortNumber;
    u8 local_u8PinNumber;
    u8 local_u8ErrorFlag;

    /*Comment!: local_u8PortNumber=Copy_u8PinIdx/8 */
    local_u8PortNumber = Copy_u8PinIdx >> DIO_DEVIED_BY_EIGHT;

    /*Comment!: Get pin number in port*/
    local_u8PinNumber = Copy_u8PinIdx % DIO_u8PINS_PER_PORT;

    /*Comment!: Check if pin is in range */
    if (local_u8PortNumber < DIO_u8NUM_OF_PORTS)
	{

	/*Comment!: Write Bit Direction */
	WRITE_BIT(*DIRECTION_PORTS_ARRAY[local_u8PortNumber], local_u8PinNumber,
		Copy_u8PinDir);

	local_u8ErrorFlag = ok;
	}

    else
	{
	local_u8ErrorFlag = error;
	}

    return local_u8ErrorFlag;
    }

extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx, u8 Copy_u8PortDir)
    {
    u8 local_u8ErrorFlag;

    /*Comment!: Check if port is in range */
    if (Copy_u8PortIdx < DIO_u8NUM_OF_PORTS)
	{

	/*Comment!: Write port direction */
	*DIRECTION_PORTS_ARRAY[Copy_u8PortIdx] = Copy_u8PortDir;

	local_u8ErrorFlag = ok;
	}

    else
	{
	local_u8ErrorFlag = error;
	}

    return local_u8ErrorFlag;
    }

extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx, u8* Copy_u8PtrToDir)
    {
    u8 local_u8PortNumber;
    u8 local_u8PinNumber;
    u8 local_u8ErrorFlag;
    u8 local_u8PinDir;

    /*Comment!: local_u8PortNumber=Copy_u8PinIdx/8 */
    local_u8PortNumber = Copy_u8PinIdx >> DIO_DEVIED_BY_EIGHT;

    /*Comment!: Get pin number in port*/
    local_u8PinNumber = Copy_u8PinIdx % DIO_u8PINS_PER_PORT;

    /*Comment!: Check if pin is in range */
    if (local_u8PortNumber < DIO_u8NUM_OF_PORTS)
	{
	/*Comment!: Get pin direction then write it */
	local_u8PinDir = GET_BIT(*DIRECTION_PORTS_ARRAY[local_u8PortNumber],
		local_u8PinNumber);

	*Copy_u8PtrToDir = local_u8PinDir;

	local_u8ErrorFlag = ok;
	}

    else
	{
	local_u8ErrorFlag = error;
	}

    return local_u8ErrorFlag;
    }

extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx, u8* Copy_u8PtrToVal)
    {
    u8 local_u8ErrorFlag;

    /*Comment!: Check port index in range or out of range*/
    if (Copy_u8PortIdx < DIO_u8NUM_OF_PORTS)
	{
	/*Comment!: Read port direction */
	*Copy_u8PtrToVal = *DIRECTION_PORTS_ARRAY[Copy_u8PortIdx];

	local_u8ErrorFlag = ok;
	}

    else
	{
	local_u8ErrorFlag = error;
	}

    return local_u8ErrorFlag;
    }

extern void DIO_voidInit(void)
    {
    u8 local_u8temp1;
    u8 local_u8temp2;

    /*****************************************************************************/
    /***************************Initiate Directions*******************************/
    /*****************************************************************************/

    /*Comment!: Initiate direction of DIO_u8PORT0*/
    local_u8temp1 = CONC(DIO_u8PIN0_INITDIR, DIO_u8PIN1_INITDIR,
	    DIO_u8PIN2_INITDIR, DIO_u8PIN3_INITDIR, DIO_u8PIN4_INITDIR,
	    DIO_u8PIN5_INITDIR, DIO_u8PIN6_INITDIR, DIO_u8PIN7_INITDIR);
    DIO_u8WritePortDir(DIO_u8PORT0, local_u8temp1);

    /*Comment!: Initiate direction of DIO_u8PORT1*/
    local_u8temp1 = CONC(DIO_u8PIN8_INITDIR, DIO_u8PIN9_INITDIR,
	    DIO_u8PIN10_INITDIR, DIO_u8PIN11_INITDIR, DIO_u8PIN12_INITDIR,
	    DIO_u8PIN13_INITDIR, DIO_u8PIN14_INITDIR, DIO_u8PIN15_INITDIR);
    DIO_u8WritePortDir(DIO_u8PORT1, local_u8temp1);

    /*Comment!: Initiate direction of DIO_u8PORT2*/
    local_u8temp1 = CONC(DIO_u8PIN16_INITDIR, DIO_u8PIN17_INITDIR,
	    DIO_u8PIN18_INITDIR, DIO_u8PIN19_INITDIR, DIO_u8PIN20_INITDIR,
	    DIO_u8PIN21_INITDIR, DIO_u8PIN22_INITDIR, DIO_u8PIN23_INITDIR);
    DIO_u8WritePortDir(DIO_u8PORT2, local_u8temp1);

    /*Comment!: Initiate direction of DIO_u8PORT3*/
    local_u8temp1 = CONC(DIO_u8PIN24_INITDIR, DIO_u8PIN25_INITDIR,
	    DIO_u8PIN26_INITDIR, DIO_u8PIN27_INITDIR, DIO_u8PIN28_INITDIR,
	    DIO_u8PIN29_INITDIR, DIO_u8PIN30_INITDIR, DIO_u8PIN31_INITDIR);
    DIO_u8WritePortDir(DIO_u8PORT3, local_u8temp1);

    /*****************************************************************************/
    /*****************************Initiate Values*********************************/
    /*****************************************************************************/

    /*Comment!: Equation to set port values */
    /*Comment!: D(direction),v(value)*/
    /*Comment!: port_value = (D'.port_value)+(D.V)*/

    /*Comment!: Initiate value of DIO_u8PORT0*/
    local_u8temp1 = CONC(DIO_u8PIN0_INITDIR, DIO_u8PIN1_INITDIR,
	    DIO_u8PIN2_INITDIR, DIO_u8PIN3_INITDIR, DIO_u8PIN4_INITDIR,
	    DIO_u8PIN5_INITDIR, DIO_u8PIN6_INITDIR,
	    DIO_u8PIN7_INITDIR) & CONC(DIO_u8PIN0_INITVAL, DIO_u8PIN1_INITVAL,
		    DIO_u8PIN2_INITVAL, DIO_u8PIN3_INITVAL, DIO_u8PIN4_INITVAL,
		    DIO_u8PIN5_INITVAL, DIO_u8PIN6_INITVAL, DIO_u8PIN7_INITVAL);
    local_u8temp2 = CONC(DIO_u8PIN0_INITDIR, DIO_u8PIN1_INITDIR,
	    DIO_u8PIN2_INITDIR, DIO_u8PIN3_INITDIR, DIO_u8PIN4_INITDIR,
	    DIO_u8PIN5_INITDIR, DIO_u8PIN6_INITDIR, DIO_u8PIN7_INITDIR);
    local_u8temp2 = ~local_u8temp2;
    local_u8temp2 &= *DIO_u8PORTA;
    *DIO_u8PORTA = local_u8temp1 | local_u8temp2;

    /*Comment!: Initiate value of DIO_u8PORT1*/
    local_u8temp1 =
	    CONC(DIO_u8PIN8_INITDIR, DIO_u8PIN9_INITDIR, DIO_u8PIN10_INITDIR,
		    DIO_u8PIN11_INITDIR, DIO_u8PIN12_INITDIR,
		    DIO_u8PIN13_INITDIR, DIO_u8PIN14_INITDIR,
		    DIO_u8PIN15_INITDIR) & CONC(DIO_u8PIN8_INITVAL, DIO_u8PIN9_INITVAL,
			    DIO_u8PIN10_INITVAL, DIO_u8PIN11_INITVAL, DIO_u8PIN12_INITVAL,
			    DIO_u8PIN13_INITVAL, DIO_u8PIN14_INITVAL, DIO_u8PIN15_INITVAL);
    local_u8temp2 = CONC(DIO_u8PIN8_INITDIR, DIO_u8PIN9_INITDIR,
	    DIO_u8PIN10_INITDIR, DIO_u8PIN11_INITDIR, DIO_u8PIN12_INITDIR,
	    DIO_u8PIN13_INITDIR, DIO_u8PIN14_INITDIR, DIO_u8PIN15_INITDIR);
    local_u8temp2 = ~local_u8temp2;
    local_u8temp2 &= *DIO_u8PORTB;
    *DIO_u8PORTB = local_u8temp1 | local_u8temp2;

    /*Comment!: Initiate value of DIO_u8PORT2*/
    local_u8temp1 =
	    CONC(DIO_u8PIN16_INITDIR, DIO_u8PIN17_INITDIR, DIO_u8PIN18_INITDIR,
		    DIO_u8PIN19_INITDIR, DIO_u8PIN20_INITDIR,
		    DIO_u8PIN21_INITDIR, DIO_u8PIN22_INITDIR,
		    DIO_u8PIN23_INITDIR) & CONC(DIO_u8PIN16_INITVAL, DIO_u8PIN17_INITVAL,
			    DIO_u8PIN18_INITVAL, DIO_u8PIN19_INITVAL, DIO_u8PIN20_INITVAL,
			    DIO_u8PIN21_INITVAL, DIO_u8PIN22_INITVAL, DIO_u8PIN23_INITVAL);
    local_u8temp2 = CONC(DIO_u8PIN16_INITDIR, DIO_u8PIN17_INITDIR,
	    DIO_u8PIN18_INITDIR, DIO_u8PIN19_INITDIR, DIO_u8PIN20_INITDIR,
	    DIO_u8PIN21_INITDIR, DIO_u8PIN22_INITDIR, DIO_u8PIN23_INITDIR);
    local_u8temp2 = ~local_u8temp2;
    local_u8temp2 &= *DIO_u8PORTC;
    *DIO_u8PORTC = local_u8temp1 | local_u8temp2;

    /*Comment!: Initiate value of DIO_u8PORT3*/
    local_u8temp1 =
	    CONC(DIO_u8PIN24_INITDIR, DIO_u8PIN25_INITDIR, DIO_u8PIN26_INITDIR,
		    DIO_u8PIN27_INITDIR, DIO_u8PIN28_INITDIR,
		    DIO_u8PIN29_INITDIR, DIO_u8PIN30_INITDIR,
		    DIO_u8PIN31_INITDIR) & CONC(DIO_u8PIN24_INITVAL, DIO_u8PIN25_INITVAL,
			    DIO_u8PIN26_INITVAL, DIO_u8PIN27_INITVAL, DIO_u8PIN28_INITVAL,
			    DIO_u8PIN29_INITVAL, DIO_u8PIN30_INITVAL, DIO_u8PIN31_INITVAL);
    local_u8temp2 = CONC(DIO_u8PIN24_INITDIR, DIO_u8PIN25_INITDIR,
	    DIO_u8PIN26_INITDIR, DIO_u8PIN27_INITDIR, DIO_u8PIN28_INITDIR,
	    DIO_u8PIN29_INITDIR, DIO_u8PIN30_INITDIR, DIO_u8PIN31_INITDIR);
    local_u8temp2 = ~local_u8temp2;
    local_u8temp2 &= *DIO_u8PORTD;
    *DIO_u8PORTA = local_u8temp1 | local_u8temp2;
    return;
    }
