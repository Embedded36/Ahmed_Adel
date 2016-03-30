#ifndef _EXINT_CONFIG_H_ 
#define _EXINT_CONFIG_H_ 
  
  
/*******************************************************/  
/**************** Public Definitions *******************/  
/*******************************************************/  
  
/*Comment!:EXTERNAL INTERRUPT STATUES */
/*Range!  :EXINT_u8DISABLED-EXINT_u8ENABLED */
  
#define EXINT_u8EXINT0STATE	EXINT_u8ENABLED
#define EXINT_u8EXINT1STATE	EXINT_u8ENABLED
#define EXINT_u8EXINT2STATE	EXINT_u8DISABLED


/*Comment!:EXTERNAL INTERRUPT MODES*/
/*Range!  :EXINT_u8RISINGEDGE-EXINT_u8FALINGEDGE-EXINT_u8LOWLEVEL-EXINT_u8LEVELCHANGE */
#define EXINT_u8EXINT0MODE	EXINT_u8RISINGEDGE

/*Range!  :EXINT_u8RISINGEDGE-EXINT_u8FALINGEDGE-EXINT_u8LOWLEVEL-EXINT_u8LEVELCHANGE */
#define EXINT_u8EXINT1MODE	EXINT_u8RISINGEDGE

/*Range!  :EXINT_u8RISINGEDGE-EXINT_u8FALINGEDGE */
#define EXINT_u8EXINT2MODE	EXINT_u8RISINGEDGE
  
#endif 
