
#ifndef _DIO_DELAY_H_
#define _DIO_DELAY_H_

#include "DelayConfig.h"

/*******************************************************/
/***************** Public Functions ********************/
/*******************************************************/
/*Comment!: 1CYC FOR NOP & 2 FOR DEC & 3 FOR JUMP & 2 FOR COMPARING, TOTAL = 8 */
/*Comment!:4 CYCLES FOR FETCH, DECODE, EXCUTE, WRITE BACK */
//#define DIO_FORLOOP_COST			(77UL)
#define DIO_u32DelayMSCounter		((Delay_u8SYSCLCK)*(14UL))

/*Comment!: Delay Function with MS */
#define voidDELAY_MS(n) do{u32 Local_u32DelayCounter;\
						for(Local_u32DelayCounter=(DIO_u32DelayMSCounter)*n;Local_u32DelayCounter>0;Local_u32DelayCounter--)\
						{__asm("NOP");}\
						}while(0)

#define voidDELAY_US(n) do{__asm("NOP");}while(0)

#endif /* _DIO_DELAY_H_ */
