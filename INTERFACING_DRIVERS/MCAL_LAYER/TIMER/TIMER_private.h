#ifndef _TIMER_PRIVATE_H_ 
#define _TIMER_PRIVATE_H_   

/*******************************************************/
/**************** Private Definitions ******************/
/*******************************************************/

/*Comment!: */

#define TIMER_u8TCCR0  ((volatile u8*)(0x53))
#define TIMER_u8TCNT0  ((volatile u8*)(0x52))
#define TIMER_u8OCR0   ((volatile u8*)(0x5c))
#define TIMER_u8TIMSK  ((volatile u8*)(0x59))
#define TIMER_u8TIFR   ((volatile u8*)(0x58))

/*******************************************************/
/*****************  Private Functions  *****************/
/*******************************************************/

#define ISR(vector, ...) 	\
		void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
		void vector(void)

#endif  
