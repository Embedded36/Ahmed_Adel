#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_
/*******************************************************/
/****************** Private Macros *********************/
/*******************************************************/
#define CONC(x0,x1,x2,x3,x4,x5,x6,x7)         CONC_HELPER(x0,x1,x2,x3,x4,x5,x6,x7)
#define CONC_HELPER(y0,y1,y2,y3,y4,y5,y6,y7)  0b##y7##y6##y5##y4##y3##y2##y1##y0
#define GET_BIT(Reg,Bit_no)                   (((Reg)>>(Bit_no))&1)
#define CLR_BIT(Reg,Bit_no)                   ((Reg)&=(~(1<<(Bit_no))))
#define SET_BIT(Reg,Bit_no)                   ((Reg)|=(1<<(Bit_no)))
#define WRITE_BIT(Reg,Bit_no,Bit_val)        do{ switch (Bit_val) {\
		case DIO_u8HIGH:\
			SET_BIT(Reg, Bit_no);\
			local_u8ErrorFlag = ok;\
			break;\
		case DIO_u8LOW:\
			CLR_BIT(Reg, Bit_no);\
			local_u8ErrorFlag = ok;\
			break;\
		default:\
			local_u8ErrorFlag = error;\
			break;\
		}}while(0)
/*******************************************************/
/***************** Register Addresses ******************/
/*******************************************************/
#define DIO_u8PORTA   ((volatile u8*)(0x3B))
#define DIO_u8DDRA    ((volatile u8*)(0x3A))
#define DIO_u8PINA    ((volatile u8*)(0x39))
#define DIO_u8PORTB   ((volatile u8*)(0x38))
#define DIO_u8DDRB    ((volatile u8*)(0x37))
#define DIO_u8PINB    ((volatile u8*)(0x36))
#define DIO_u8PORTC   ((volatile u8*)(0x35))
#define DIO_u8DDRC    ((volatile u8*)(0x34))
#define DIO_u8PINC    ((volatile u8*)(0x33))
#define DIO_u8PORTD   ((volatile u8*)(0x32))
#define DIO_u8DDRD    ((volatile u8*)(0x31))
#define DIO_u8PIND    ((volatile u8*)(0x30))
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
/***************** Private Definitions *****************/
/*******************************************************/
#define  DIO_u8PINS_PER_PORT 8
#define  DIO_u8NUM_OF_PORTS  4
#define  DIO_ZERO            0
#define DIO_DEVIED_BY_EIGHT  3
#endif /* DIO_PRIVATE_H_ */
