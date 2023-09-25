/** @file main.c 
 *  @brief use case of... 
 *  @author Umar Ba LoopFocus jUmarB@protonmail.com
 */ 

#include <semaphore.h>
#include <stdlib.h> 
#include <stdio.h>
#include <pthread.h> 
#include <errno.h> 
#include <err.h> 
#include <unistd.h>

#include "smphr.h" 

int
main ()
{

  errno = 0 ; 
  //smphr_t  agent  ; 
  //configure(&agent , _nullable) ;

  sema_t * bgent =  configure_sa( _void_0h, _void_0h) ;   
  if (bgent == _void_0h )  
  {
    errx ( 1 , "configure_sa fault" ) ; 
  }

  smphr_t  * agent =  ( smphr_t * ) bgent  ; 

#ifdef NAMEDSMPR 
  char * file = NSF ; 
  sem_unlink (file);
  
  agent.smphr_h = agent.smphr_init(NSF , O_CREAT  ,  S_IRUSR | S_IWUSR , 0) ;    
  if ( agent.smphr_h == SEM_FAILED )
  {
     errx ( ~0, "Fail to   init agent") ; 
  }

#endif 

  pthread_t  thread_counter ;
  pthread_t  thread_reset   ;  
  pthread_create (&thread_counter , _nullable , count , agent) ; 
  pthread_create (&thread_reset , _nullable , reset , agent) ;

  pthread_join(thread_counter , _nullable) ; 
  pthread_join(thread_reset , _nullable) ;

  
  agent->smphr_terminate(agent->smphr_h); 


  return EXIT_SUCCESS ; 
}
