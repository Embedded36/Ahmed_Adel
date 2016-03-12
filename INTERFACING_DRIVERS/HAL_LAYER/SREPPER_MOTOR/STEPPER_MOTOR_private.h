#ifndef _STEPPER_MOTOR_PRIVATE_H_ 
#define _STEPPER_MOTOR_PRIVATE_H_   
  
  
/*******************************************************/  
/**************** Private Definitions ******************/  
/*******************************************************/  
  
/*Comment!: Motor state*/
  static u8 STEPPER_MOTOR_u8State=1;
  
/*******************************************************/  
/*****************  Private Functions  *****************/  
/*******************************************************/  
#define GET_BIT(Reg,Bit_no)       (((Reg)>>(Bit_no))&1)
  
#endif  
