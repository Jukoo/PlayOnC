#include <avr/io.h> 
#include <util/delay.h>

#include "pushbtn.h"

void main () { 
    __configure() ; 

    test()  ; 
    while( 1 ) 
    {
       on_off_led_shift()  ;
    }
} 
