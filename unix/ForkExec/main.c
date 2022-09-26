#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <errno.h>   
#include <sys/wait.h> 

#include  "include/fork_and_execute.h"

int
main ( int argc , char **argv )  { 

    if (argc <= 1 )  usage ( *argv ) ;  

    list_stdargs(argv) ; 
       
    char *exectarget = *(argv+1) ; 
    char *args_super_option  =  argv[2];  


    BinLoc *bl  =  &(struct BinLoc  * )  { 0 , 0 }  ;     
    has_command(exectarget , bl ) ;

#ifdef  PROCESS_ISOLATION
   pid_t  clone_process  = create_subprocess() ;
   switch (clone_process)  
   {
       case  0  :  
           openbf(bl  , args_super_option) ; 
           break ; 
           
        default  :  
           cp_handler() ;  
           break ; 
   }
#else  
    while (*++argv ) 
    {
        show_env(*argv) ;  
    }
    openbf (bl , args_super_option)  ;
#endif  

    
    return EXIT_SUCCESS ; 
} 
