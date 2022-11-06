/* USART (UNIVERSAL  SYNCHRONOUS and ASYNCHONOUS SERIAL RECEIVER  & TRANSMITER ) 
 * Copyright (C) 2022 , Umar  <jUmarB@protonmail.com>  
 */

#ifndef  __usart
#define  __usart 

/** 
 * define  the default baudrate 
 */
#ifndef  USART_DEFAULT_BAUDERATE_BPS  
#define  USART_DEFAULT_BAUDERATE_BPS  9600  
#endif  

#define  F_CPU  16000000UL 

#define  BAUDERATE_PRESCALER (  F_CPU /(DEFAULT_BAUDERATE_BPS * 0x10 ) -1) 

#ifdef __cpluscplus  
extern "C" {  
#endif 

typedef  enum  { 
   USART_ASYNC_MODE  = (0 <<UMSEL00) 
}USART_MODE_COM ;  

typedef  enum  { 
    USART_PARITY_DESABLED   = ( 0 << UPM00),
    USART_PARITY_EVEN       = ( 2 << UPM00), 
    USART_PARITY_ODD        = ( 3 << UPM00) 
} USART_PARITY_MODE ; 


typedef enum  {  
    USART_STOP_BIT_1   =   (0 << USBS0), 
    USART_STOP_BIT_2   =   (1 << USBS0) 
} USART_STOP_BIT_FRAME ; 


typedef enum  {  
    USART_DATA_BIT_5   = ( 0 << UCSZ00) , 
    USART_DATA_BIT_6   = ( 1 << UCSZ00) , 
    USART_DATA_BIT_7   = ( 2 << UCSZ00) , 
    USART_DATA_BIT_8   = ( 3 << UCSZ00) , 
    USART_DATA_BIT_9   = ( 4 << UCSZ00)  
} USART_DATA_BIT_LENGTH ;


typedef  enum  { 
    TX  = ( 1  << TXEN0) , 
    RX  = ( 1  << RXEN0) , 
    TX_RX =  TX |  RX 
} USART_TRX  ; 


typedef struct  {  
    USART_MODE_COM mode ;
    USART_PARITY_MODE parity_mode ; 
    USART_STOP_BIT_FRAME  stop_bit ;
    USART_DATA_BIT_LENGTH data ;
} UsartFrame ;  




void _init_bauderate_lh_register () ;  
void _set_usart_frame_register ( UsartFrame  & )  ;  
void _set_usart_trx (USART_TRX )  ; 



void usart_transmission_polling ( unsigned char  data_byte  ) ; 




#ifdef __cpluscplus 
}
#endif 



#endif 

