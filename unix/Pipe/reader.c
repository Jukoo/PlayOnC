#include <stdio.h> 
#include <stdlib.h> 


#include "ipc.h" 

int
main ( int argc , char **argv ) { 
    
    Ipc_t  ipc  ; 
    Ipmc_t ipmc  = {&ipc} ; 

    fsfifo( &ipmc ,  (void  * ) 0) ;

    readstream(&ipmc) ;  
    
    fprintf (stdout ,  "%s\n"  , ipmc.ipc->ipc_mesgbuff) ; 
    
    
    return EXIT_SUCCESS ;    
}
