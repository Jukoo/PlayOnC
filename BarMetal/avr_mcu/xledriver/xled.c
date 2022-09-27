#include  <avr/io.h>  
#include  <util/delay.h> 

#include "include/xled_regconf.h" 
#include "include/xled.h"


void  __configure ( MODE  __mode )  {  

    switch  ( __mode ) 
    {
        case  OUTPUT : 
#ifdef K2KEFFECT 
           DEF_AVR_IO_DATA_DIRECTION_REGISTER_X |=SETTING_GPIO_TARGET_K2 ; 
#else 
           DEF_AVR_IO_DATA_DIRECTION_REGISTER_X |=SETTING_GPIO_TARGET ;  
#endif 
           break ; 
        case INPUT: 
           DEF_AVR_IO_DATA_DIRECTION_REGISTER_X &=!SETTING_GPIO_TARGET ; 
           break ; 
    }

}
 
void blink_test ( )  {  
     
    DEF_AVR_IO_PORT_X |=  SETTING_GPIO_TARGET_K2 ;// |!SETTING_GPIO_TARGET) ;    
    _delay_ms(1000) ; 
    DEF_AVR_IO_PORT_X ^=  SETTING_GPIO_TARGET_K2 ; //|!SETTING_GPIO_TARGET) ; 
    _delay_ms(1000) ; 
}

void  _delay ( int duration_ms ) { 
    int  _s = 0  ; 
    while  ( _s  <   duration_ms) 
    {
        _delay_ms(1) ; 
        _s++ ; 
    } 
}


void blk2xtimes ( int  pin_select [] ,  int delay_time ,  int size )   {  
    
    for ( int  t=0   ; t  < size  ; t++ )  
    {
        DEF_AVR_IO_PORT_X =  pin_select[t]  ^ 1; 
        _delay(delay_time)  ;
         
    }
} 


void  k2k (int  pin_select[]  , int size  ) {  
    
    //->  
    for  ( int i = 0 ; i < size ; i++ ) 
    {
        DEF_AVR_IO_PORT_X  |= pin_select[i]     ; 
        _delay(100) ;  
    }  

    //<- 
    for ( int  j = size  ; j > 0 ;  j-- ) 
    {
        DEF_AVR_IO_PORT_X  &=!pin_select[j] ; 
        _delay(100) ; 
        DEF_AVR_IO_PORT_X   |=pin_select[j] ; 
        _delay(100) ; 
     }
} 

