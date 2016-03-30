#ifndef _EXINT_PRIVATE_H_ 
#define _EXINT_PRIVATE_H_   
  
  
/*******************************************************/  
/**************** Private Definitions ******************/  
/*******************************************************/  
  
/*Comment!: */ 
#define EXINT_u8DISABLED 0

#define EXINT_u8ENABLED  1

#define EXINT_u8ISC00 0

#define EXINT_u8ISC01 1

#define EXINT_u8ISC2 6

#define EXINT_u8ISC10 2

#define EXINT_u8ISC11 3



#define EXINT_u8GICR      ((volatile u8*)(0x5B))

#define EXINT_u8GIFR      ((volatile u8*)(0x5A))

#define EXINT_u8MCUCR     ((volatile u8*)(0x55))

#define EXINT_u8MCUCSR    ((volatile u8*)(0x54))



/*******************************************************/  
/*****************  Private Functions  *****************/  
/*******************************************************/  
  
#define CLR_BIT(Reg,Bit_no)                   ((Reg)&=(~(1<<(Bit_no))))
#define SET_BIT(Reg,Bit_no)                   ((Reg)|=(1<<(Bit_no)))

#define ISR(vector, ...) 	\
		void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
		void vector(void)


#endif  
