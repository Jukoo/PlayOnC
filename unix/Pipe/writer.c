#include <stdlib.h> 
#include <stdio.h>  

#include "ipc.h" 

int
main  ( int argc , char  ** argv  ) {

    Ipc_t ipc  ; 
    Ipmc_t ipmc =  {&ipc} ; 
    
    fsfifo(&ipmc  , (void  *) 0 /* Use default  file  namedpipe  */) ; 

    writestream ( &ipmc  , "MSG From Writer \n") ;  
    

  
    return EXIT_SUCCESS ; 
} 
