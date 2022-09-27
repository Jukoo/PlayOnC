#include <avr/io.h> 
#include  <util/delay.h>

#include  "pushbtn.h" 

int  portb_gpio[2]  = { _BV(PORTD4)  , _BV(PORTD6)} ; 

void   __configure ()  { 
 //TODO   :
 // SET PIN 4 AND 6 TO OUTPUT  
 // SET PIN 8  TO INPUT  
     DDRD  |= _BV(DDD4) | _BV(DDD6) ; //(1<<4) |  (1<<6)  ; 
     DDRB  &= !_BV(DDB0)  ; //!(1<<0) ; 
                     

}


void  _delay(int  __duration_timestamp )   {  
    
    int __c = 0  ; 
    while (__c < __duration_timestamp ) 
    {
      _delay_ms(1) ; 
      __c++ ;  
    }
     
}

void initial_stat ( ) { 
    
    PORTD  &= !_BV(PORTD6) ;  
    PORTD  |= _BV(PORTD4) ;  
    
}


void on_off_led_shift ()  { 
    
    int push_signal_satus = (PINB & _BV(PORTB0)) ; 
    if (push_signal_satus) 
    {
        PORTD |=  _BV(PORTD6) ; 
        PORTD &= !_BV(PORTD4) ; 
    }else
        initial_stat();  
} 
