#ifndef  __fork_and_execute_binary_file
#define  __fork_and_execute_binary_file

#ifndef UBIN_PATH  
#define UBIN_PATH  "/usr/bin/"   
#endif  


typedef  struct    {  
    char location[0xff]; 
    char *binexec  ; 
} BinLoc  ; 

#ifdef  PROCESS_ISOLATION  
//! handle created child process   
void  cp_handler  () ;   
pid_t create_subprocess () ;

#define   WHANDLER_MSG(RECEIVEDSIG) fprintf(stdout , "exit [%i] \n",RECEIVEDSIG) ;\
    exit(RECEIVEDSIG);

#endif   


extern  char **environ ;
/**
 * display  usage 
 */
void usage (char * __pb ) ;   

/**
 * list all content  
 */
void list_stdargs(char *const * )  ; 

/**
 * show all environment variable 
 */
void  show_env(char*envar_key) ;  

/**  
 * Check if binary file exist and dump into  BinLop  structure  
 * otherwise raise  an Assertion error   
 */
char  *has_command (char  const * binexe   , BinLoc * )  ;  

/**
 * excute  binary file 
 */
static void execute(BinLoc *   , char  const *extra_arguments)  ;

/**
 * open to childprocess  # openbf 
 * create  a child process  and execute  binary file 
 */
void openbf (  BinLoc * ,  char const * )     ; 


#endif  
