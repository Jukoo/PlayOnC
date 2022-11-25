#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <assert.h> 


#include "ipc.h"

int wstatus ;  

int 
main ( int argc  , char **argv ) {

    Ipc_t interpcom  ; 
    (void ) ipc_instanciate ( &interpcom) ;
    

    pid_t childprocess   = fork() ; 
    
    assert( childprocess != -1 ) ;   
    
    if  ( childprocess  == 0 )  
    { 
        ipc_read ( &interpcom , (void * ) 0 )  ; 
        fprintf  ( stdout , "%s \n" , interpcom.ipc_mesgbuff )  ; 
    }
    
    ipc_write ( &interpcom , "ORIGINE::") ;  
    
    wait(&wstatus ) ;  
    

     
    
    return EXIT_SUCCESS ; 
    
}  
