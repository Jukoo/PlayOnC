#include <stdlib.h>
#include <stdio.h> 
#include <pthread.h> 
#include <string.h> 
#include <errno.h>  

#include  "include/threadmanip.h" 


pthread_mutex_t  mutex  = (pthread_mutex_t ) PTHREAD_MUTEX_INITIALIZER ;   
pthread_cond_t   cond   = (pthread_cond_t  ) PTHREAD_COND_INITIALIZER ;

void initialize_thread_context_manager (ThreadContext  * T  ) { 
    T->mutex_hdl =  (pthread_mutex_t  ) PTHREAD_MUTEX_INITIALIZER  ; 
    T->cond_hdl  =  (pthread_cond_t  )  PTHREAD_COND_INITIALIZER ; 
}  

ThreadManager * create_new_thread_hdl  () {   
    ThreadManager  *__tm =  malloc(sizeof(*__tm)) ;
    __tm->parent_thread = (void *  ) 0 ; 
    __tm->next_thread   = (void  * ) 0 ; 
   return  __tm ;  
} 

ThreadManager * thread_link  ( ThreadManager * thread_hdl_node_target  )  {  
    
    ThreadManager  * new_thread_manager_node   =  malloc ( sizeof ( *new_thread_manager_node)) ; 
    thread_hdl_node_target->next_thread = new_thread_manager_node ; 
    new_thread_manager_node->next_thread =  ( void * )0 ; 
    new_thread_manager_node->parent_thread =  thread_hdl_node_target ;  
     
    return  new_thread_manager_node  ;  

} 

#ifdef  THRD_HDL_STDIN 

THRD_HDL_STDIN  void *thread_catch_stdin(  void  *args ) { 
    thread_safe_scan( (TStdin *) args) ;

    pthread_exit((void *) 0) ;  
}


static  void thread_safe_scan (TStdin  * stdin_t ) { 
    
    fprintf(stdout , "%s\n" , stdin_t->mesg ) ; 
    
    char  input_buffer[0xff]  ={ 0 } ;  
    if ( fgets(input_buffer  ,  0xff  , stdin  ) == (void*)  0 ) 
    { 
        stdin_flush() ; 
        perror("stdin  error ") ; 
        exit(EXIT_FAILURE) ; 
    }
     
    char  *endpoint  = (void * ) 0 ; 
    endpoint = strrchr ( input_buffer ,  0xa ) ;  
    if (endpoint !=  (void *) 0 )  
    {
        *endpoint =  0 ; 
    } 

    stdin_t->data = strtol ( input_buffer ,  NULL , 10 )  ;

    fprintf(stdout , "data -> %i \n" ,stdin_t->data ) ;  

    stdin_flush() ; 
}

static void stdin_flush() { 
    char  vcurs  =-1 ; 
    while  ( vcurs != 0   &&  vcurs !=EOF ) { 
        vcurs  =getchar() ; 
    } 
}

#endif  //!  THRD_HDL_STDIN 
        //

#ifdef  THRD_CLOCK_TIME 
#define THRD_CLOCK_TIME 
extern int counter  = 0 ;  

THRD_CLOCK_TIME  void *  thrd_time_counter ( void * args )   {
    
    fprintf(stdout , "start counting \n") ; 
    while ( counter <  0x64 )
    {
        counter++  ; 
        printf("%i\n",counter) ;  
        if ( counter ==  RESET_AT )  
        {
            fprintf(stdout , "trigger the signal \n" ) ; 
            pthread_mutex_lock(&mutex )   ;  
            pthread_cond_signal(&cond)   ; 
            pthread_mutex_unlock(&mutex) ;  
           
        } 

        sleep(1) ; 
    }

    pthread_exit( (void *)0 ) ; 
} 

THRD_CLOCK_TIME  void *   thrd_reset(void *  args )  { 
    
     
    while (1) 
    {   puts("waiting for signal ");

        pthread_mutex_lock(&mutex)   ;  
        pthread_cond_wait(&cond  ,  &mutex) ;  
        fprintf(stdout , "resting counter \n")  ; 
        counter= 0 ;  
        pthread_mutex_unlock(&mutex); 
        puts("releasing ... ") ; 

    }

    pthread_exit((void *) 0) ; 

}  

#endif  //!THRD_CLOCK_TIME   


