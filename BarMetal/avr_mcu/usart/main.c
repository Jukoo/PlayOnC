/*
 *
 */

#include  <avr/io.h> 
#include  <util/delay.h> 

#include  "include/ioserial.h"

void  main ()  { 
    _init_bauderate_lh_register() ; 

    UsartFrame  uframe  = {
        .mode = USART_ASYNC_MODE ,
        .parity_mode = USART_PARITY_DESABLED ,     
        .stop_bit = USART_STOP_BIT_1 ,  
        .data = USART_DATA_BIT_8}; 
    _set_usart_fram_register(&uframe) ;  
    
    _set_usart_rxtx(TX_RX) ;  
    
}
