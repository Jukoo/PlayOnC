#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <ctype.h> 
#include <string.h>
#include <unistd.h>  

#include "include/fex.h" 


int  waitstatus ;   
void  usage ( char  *programme_basename  )   { 
    fprintf(stderr  ,  "%s  <arguments ...>\n", programme_basename) ;
    exit(EXIT_FAILURE) ; 
}  

void list_stdargs ( char *const  *argv )  {  
    
    while (*++argv != NULL) 
        fprintf(stdout , "[ %s ] \n", *argv);  
    
    
}

void show_env (char *envar_key)  { 
   if ( envar_key == (void * ) 0 )   
   {
       list_stdargs(environ) ;
       exit(EXIT_SUCCESS) ;  
   } 

   char key[254] = {0} ;  
   assert (key != NULL) ;  
   int i = 0  ; 
   while  (*envar_key) 
   {
       int  each_unicode_char  = toupper(*envar_key++) ;  
       key[i++] =  each_unicode_char; 
        
   }

   char  *found_env = getenv(key) ;  
   if (found_env)  
       fprintf(stdout ,  "%s => %s\n" , key , getenv(key) ) ;  
   
   memset(key ,  0 ,  254 ) ; //flush  

}

char  *has_command  (char const * binary_file_location  , BinLoc  * bl)  {  
    strcpy(bl->location  , UBIN_PATH )  ;  
    bl->binexec=(char *) binary_file_location ;  
    strcat(bl->location,bl->binexec) ;  

    assert ( access(bl->binexec ,  F_OK))  ;   
    return  bl->location ;  
}

static void execute( BinLoc *bl  ,  char const  * xargs )   {   

    char *args[] = {  bl->binexec , xargs  ,  (void *) 0 }  ; 
     
    if (execv(bl->location ,args)  == -1 ) 
    {
 #ifndef PROCESS_ISOLATION  
        exit(EXIT_FAILURE) ; 
#else  
        
        perror("execv: ") ; 
        exit(EXIT_FAILURE);  
#endif 
    }
}  


void openbf (  BinLoc  *bl ,  char const * xtrargs)  {
#ifdef PROCESS_ISOLATION  
    //!that's mean  you create a fork 
    fprintf(stdout , "father process %i \n child process %i \n" , (int) getppid()  , (int)getpid());  
    execute(bl  , xtrargs)  ;  
#endif 
    execute(bl  , xtrargs)  ;  
    
}

#ifdef PROCESS_ISOLATION
#include <sys/wait.h> 
#include <errno.h> 
pid_t create_subprocess  () {  
    pid_t fork_process  =-1  ;  
    while ( fork_process == -1   || errno == EAGAIN) 
    {
         fork_process = fork() ;  
    }
    return  fork_process ;  
} 
void cp_handler()  {
     fprintf(stdout , "Watching  Isolated process\n") ;  
     if (wait(&waitstatus) == -1 ) 
     {
         perror("wait : ") ;  
         exit(EXIT_FAILURE) ; 
     }

     if (WIFEXITED(waitstatus)) WHANDLER_MSG(WEXITSTATUS(waitstatus))   ; 
     if (WIFSIGNALED(waitstatus)|| WCOREDUMP(waitstatus)) WHANDLER_MSG(WTERMSIG(waitstatus)) ; 
} 
#endif 
