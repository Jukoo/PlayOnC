#include <avr/io.h> 
#include <util/delay.h> 

#include "include/xled.h" 

//! TODO :  make  pin selection more dynamic ... 
int   io_pins  [3] =  { _BV(PORTD6), _BV(PORTD4), _BV(PORTD2) }   ; 
int   io_pins_k2k  [5] =  { _BV(PORTD6),_BV(PORTD5), _BV(PORTD4),_BV(PORTD3), _BV(PORTD2) }   ; 

void  main ()  {
    MODE IO_MODE = OUTPUT ; 
    __configure(IO_MODE) ;

#ifdef BLK2XTIME  
    int time   = TIME_DELAY ;   
    blink_test() ;  
#endif 
    while (1) 
    {
        
#ifdef  BLK2XTIME 
        if ( time == 0 )  
        {
            time = TIME_DELAY ;
            blink_test() ;  
        }
        time -= DECREASE_DELAY_TIMER ; 
        blk2xtimes(io_pins ,  time  , 3   ) ; 
#endif 

#ifdef K2KEFFECT 
        k2k(io_pins_k2k , 5 ) ; 
#endif 
    }
} 
