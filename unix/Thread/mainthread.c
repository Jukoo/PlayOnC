#include  <stdio.h> 
#include  <stdlib.h> 
#include  <pthread.h>  
#include  <errno.h>  
#include  <string.h> 


#include  "include/threadmanip.h" 

#define  DBGP puts("*") ; 
int 
main ()  { 
     
    ThreadContext th_ctx ;

    initialize_thread_context_manager (&th_ctx) ; 

    ThreadManager  *tm1 =  create_new_thread_hdl()  ;
    ThreadManager  *tm2 =  thread_link(tm1) ; 
    
      
#ifdef  THRD_HDL_STDIN  
    TStdin  *stdin_t  = malloc(sizeof(*stdin_t))  ; 
    stdin_t->data  = 0 ;  
    strcpy(stdin_t->mesg  ,  "please give a number") ;    
      
    if ( pthread_create (&tm1->thread_hdl,  ( void *) 0 , thread_catch_stdin ,  stdin_t ) != 0 )  
    { 
        perror("thread error") ; 
        exit(EXIT_FAILURE) ; 
        
    }  
    pthread_join(tm1->thread_hdl , (void *) 0 ) ; 
   

    fprintf(stdout ,  "incremente value +1  %i\n" ,  stdin_t->data+1 )  ;      
    free(stdin_t)  ; 

#endif  
     
#ifdef  THRD_CLOCK_TIME

   if (pthread_create (&tm1->thread_hdl  , (void *)0 , thrd_time_counter , &th_ctx) != 0 ) 
   {
       perror("thread counter  error") ; 
       exit(EXIT_FAILURE) ; 
   } 
   

   if (pthread_create (&tm2->thread_hdl  , (void *)0 , thrd_reset ,  &th_ctx) !=0 ) 
   {
       perror("thread reset  error") ; 
       exit(EXIT_FAILURE) ; 
   } 

   pthread_join(tm1->thread_hdl , (void *)0) ; 
   pthread_join(tm2->thread_hdl , (void *)0) ; 

#endif   

   free(tm1) ; free(tm2) ;  

   return EXIT_SUCCESS ; 

} 
