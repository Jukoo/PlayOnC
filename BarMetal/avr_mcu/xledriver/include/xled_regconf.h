/** 
 * LED DRIVER ANIMATION 
 * Copyright (C)  2022 , Umar @openwire  
 */

#ifndef  __xled_register_configuration 
#define  __xled_register_configuration 

/** 
 * Setting up default configuration  
 * for IO   & DATA REGISTER  
 */

#ifndef  DEF_AVR_IO_DATA_DIRECTION_REGISTER_X   
#define  DEF_AVR_IO_DATA_DIRECTION_REGISTER_X   DDRD  
#endif  

#ifndef DEF_AVR_IO_PORT_X 
#define DEF_AVR_IO_PORT_X  PORTD   
#endif   

//! GPIO  SELECT  
#ifndef   SETTING_GPIO_TARGET  
#define   SETTING_GPIO_TARGET  0x00000054    
#endif  




#endif  
