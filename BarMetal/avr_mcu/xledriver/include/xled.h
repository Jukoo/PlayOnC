/**  
 * LED  DRIVER ANIMATION  
 * Copyright  (C) 2022 , Umar  @openwire
 */

#ifndef  __xled_driver_animation 
#define  __xled_driver_animation   


typedef enum   { 
    INPUT  , 
    OUTPUT 
} MODE  ; 


void  __configure( MODE __mode )  ; 
void  blink_test() ; 
void  _delay(int duration_ms )    ; 

#ifdef  BLK2XTIME 
#define DECREASE_DELAY_TIMER 0x000000c8 
#define TIME_DELAY           0x000003e8  
void  blk2xtimes(int [] , int  delay_time , int _size)  ; 
#endif  

#ifdef  K2KEFFECT 
#define SETTING_GPIO_TARGET_K2  0x0000007c 
void  k2k  ( int []  ,   int size ) ; 
#endif 

#endif  //__xled_h 
