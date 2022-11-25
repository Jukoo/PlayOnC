/* ipc  - inter process channel communication   
 * Copyright(c) , 2022 , Umar @OpenWire Lab 
 *  
 */ 
#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <errno.h>  
#include <assert.h> 
#include <signal.h>  
#include <string.h>  
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h> 


#include "ipc.h"

static void flushbuffer  ( char * string_buffer ) {   
    memset ( string_buffer , 0 , IPC_MAXLMTBUFF) ; 
} 

Ipc_t * ipc_instanciate ( Ipc_t  *  ipc  )  {   
    if  ( pipe(ipc->ipc_pipes)  == -1 )  
    {
        raise(SIGABRT) ;  
    }
    
    ipc->ipc_fdw =  ipc->ipc_pipes[IPC_STDIN]  ; 
    ipc->ipc_fdr =  ipc->ipc_pipes[IPC_STDOUT] ;  
    
    ipc->flush_imb = flushbuffer ;  
    ipc->flush_imb(ipc->ipc_mesgbuff) ; 

    return  ipc ; 
}  


Ipc_t *ipc_write ( Ipc_t  * ipc  , char  *restrict  mesg )  { 
    IPC_CLOSE(ipc->ipc_fdr);  
    ipc->flush_imb(ipc->ipc_mesgbuff); //! flush ipc buffer before   
    
    memcpy ( ipc->ipc_mesgbuff ,  mesg  , IPC_MAXLMTBUFF ) ; 
    write(ipc->ipc_fdw  , ipc->ipc_mesgbuff ,  IPC_MAXLMTBUFF)  ;  
    return ipc ; 
} 

Ipc_t *ipc_read( Ipc_t * ipc , char * __holer)  {   
    IPC_CLOSE(ipc->ipc_fdw) ;  
    read(ipc->ipc_fdr , ipc->ipc_mesgbuff  ,  IPC_MAXLMTBUFF ) ;   
    return  ipc ; 
}

static Bool  ae_fsfifo (char  *namedpipe )  {  
  if  ( access(namedpipe  , F_OK )  != 0 )  
  { 
      return  false  ; 
  }  
  
  return true  ; 
} 

Ipmc_t * fsfifo ( Ipmc_t * ipmc  , char *restrict  namedpipe  )  {  
    
   if (namedpipe != (void * ) 0 )  
   {  
       memcpy(ipmc->fnpipe  ,  namedpipe , 0xfe ) ;   
   }else  
       strcpy(ipmc->fnpipe , IPC_MKFIFO_FN) ;  
   
   if ( ae_fsfifo(ipmc->fnpipe) == true )  return   ipmc  ;   

   if ( mkfifo (ipmc->fnpipe , S_IRWXU )  != 0 )  
   {
       perror ( "IPC Error :") ; 
       return   ( void * ) 0 ; 
   }

   return ipmc ; 

}

Ipmc_t*  readstream  ( Ipmc_t  * ipmc   )  {
  
    ipmc->ipc->ipc_fdr =  open ( ipmc->fnpipe , O_RDONLY ) ; 
    
    int  fdr  = ipmc->ipc->ipc_fdr  ; 
    if ( fdr   == -1 )  
    {
        perror ("Readstream Namedpide Error" ) ; 
        exit(EXIT_FAILURE) ; 
    }
    
    read(
            fdr,
            ipmc->ipc->ipc_mesgbuff ,
            IPC_MAXLMTBUFF
        ); 

    close (fdr) ; 

   return   ipmc ; 
} 

Ipmc_t * writestream( Ipmc_t *ipmc  , char *restrict  smthing ) {  
    ipmc->ipc->ipc_fdw = open ( ipmc->fnpipe  , O_WRONLY) ;  
    int fdw  = ipmc->ipc->ipc_fdw ;
    
    if  (fdw  == -1 ) 
    {
        perror ("Writestream Namedpide Error" ) ; 
        exit(EXIT_FAILURE) ;  
    }  
    if (  smthing != ( void * ) 0) 
    { 
        memcpy  ( ipmc->ipc->ipc_mesgbuff , smthing ,  IPC_MAXLMTBUFF ) ; 
    }

    write (fdw ,  ipmc->ipc->ipc_mesgbuff , IPC_MAXLMTBUFF ) ; 

   close (fdw);   
   
   return   ipmc ; 
}
