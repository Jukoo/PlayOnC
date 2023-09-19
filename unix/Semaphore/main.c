/** @file main.c 
 *  @brief use case of... 
 *  @author Umar Ba LoopFocus jUmarB@protonmail.com
 */ 

#include <stdlib.h> 
#include <stdio.h>
#include <pthread.h> 

#include "smphr.h" 

int
main ()
{

  smphr_t  agent  ; 
  
  configure(&agent , _nullable) ; 
  
  pthread_t  thread_counter ; 
  pthread_t  thread_reset   ;  
   
  pthread_create (&thread_counter , _nullable , count , &agent) ; 
  pthread_create (&thread_reset , _nullable , reset , &agent) ;

  pthread_join(thread_counter , _nullable) ; 
  pthread_join(thread_reset , _nullable) ; 


  return EXIT_SUCCESS ; 
}
