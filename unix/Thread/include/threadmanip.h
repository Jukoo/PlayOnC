#ifndef  __thread_manipulation  
#define  __thread_manipulation 



typedef struct  ThreadManager   {
    struct  ThreadManager *parent_thread  ;  
    pthread_t  thread_hdl ; 
    struct ThreadManager  * next_thread ;
}ThreadManager ;  
 
typedef  struct ThreadContext {
    pthread_mutex_t  mutex_hdl  ; 
    pthread_cond_t   cond_hdl ; 
} ThreadContext ; 

void  initialize_thread_context_manager ( ThreadContext  * )  ;  

ThreadManager * create_new_thread_hdl  ()  ; 

//! create  a link between thread   
ThreadManager * thread_link  ( ThreadManager  * last_thread_manager )  ;  

//! free all  thread  that  has been  allocated  using malloc ...  
void  thread_release_all ( ThreadManager *  thread_manager_origin  )  ; 

#ifdef THRD_HDL_STDIN  
#define THRD_HDL_STDIN 
typedef  struct  TStdin { 
    int  data ; 
    char mesg[0xff]  ;  
} TStdin   ;  

//! scanf like  but more secure  ...  
static  void  thread_safe_scan (TStdin * _tstdin) ;  
//! clean  stdin buffer  
static  void  stdin_flush () ;  
//!  thread coroutine that attend  the user  to give data  
THRD_HDL_STDIN  void * thread_catch_stdin( void  *)  ;   

#endif //THRD_HDL_STDIN 


#ifdef  THRD_CLOCK_TIME 
#define THRD_CLOCK_TIME 

#ifndef RESET_AT  
#define RESET_AT  3 
#endif 

#ifndef LIMIT_COUNTER  
#define LIMIT_COUNTER 0x64 
#endif 

extern int counter  ; 

extern  pthread_mutex_t  mutex  ; 
extern  pthread_cond_t   cond   ;  
THRD_CLOCK_TIME void  *thrd_time_counter( void *) ; 
THRD_CLOCK_TIME void  *thrd_reset(void *) ; 

#endif // THRD_CLOCK_TIME 

#endif  
