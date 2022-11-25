/* ipc  - inter process channel communication   
 * Copyright(c) , 2022 , Umar @OpenWire Lab 
 *  
 */ 
#ifndef  _IPC_
#define  _IPC_  

#define  IPC_MAXLMTBUFF  0xff 
#define  IO_PIPE 2  
#define  IPC_CLOSE(__TARGET_FD)  close(__TARGET_FD)  
#define  IPC_MKFIFO_FN  ".interpc.fifo"
#define  IPC_STDOUT 0  
#define  IPC_STDIN  1 

typedef struct   { 
    int ipc_pipes[IO_PIPE]; 
    int ipc_fdw  ;  
    int ipc_fdr  ; 
    char ipc_mesgbuff[IPC_MAXLMTBUFF]  ;  
    void (*flush_imb) (char*)  ;  
}Ipc_t  ; 


typedef struct  { 
    Ipc_t  *ipc  ; 
    char fnpipe[IPC_MAXLMTBUFF]  ; 
    
}Ipmc_t  ; 
 
typedef enum  { 
    false , true 
} Bool; 

typedef struct  {  
    char  send_mesg[IPC_MAXLMTBUFF] ; 
    
}Argflag_t ; 

 
static void  flushbuffer  ( char * _buffer )  ; 

Ipc_t  *ipc_instanciate  (Ipc_t * ) ;   
Ipc_t  *ipc_write(Ipc_t  *ipc , char  *restrict __mesg ) ; 
Ipc_t  *ipc_read (Ipc_t  *ipc , char  *__holder  ) ; 

/**
 * argument  parser  
 * options :  
 * -s  --send  -> to send message  to childprocess
 * -f  --fifo  -> create  fifo file  . 
 * ... 
 */
void argument_parser  ( int __argc ,  char * const * __argv  , Argflag_t  * ) ; 
static Bool ae_fsfifo ( char * namedpipe  )  ; 

Ipmc_t * fsfifo(Ipmc_t  *  ,  char *restrict  __namedpipe  ) ;  
Ipmc_t * readstream( Ipmc_t * ) ;
Ipmc_t * writestream(Ipmc_t *  ,  char *restrict _something) ; 


#endif
