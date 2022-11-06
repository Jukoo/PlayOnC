/*
 *
 *
 */

#include <avr/io.h> 
#include "include/ioserial.h" 



void _init_bauderate_lh_register()  { 
    UBRR0H =  BAUDERATE_PRESCALER >>8 ; 
    UBRR0L =  BAUDERATE_PRESCALER ; 
} 

void _set_usart_fram_register ( UsartFrame &  uframe ) { 
    
    UCSR0C  =  uframe->mode |  uframe->parity_mode | uframe->stop_bit | uframe->data ;  
} 

void _set_usart_rxtx (USART_TRX  TX ) { 
    
    UCSR0B  = TX ;   
} 

