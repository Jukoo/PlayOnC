/** @file  smphr.c 
 *  @brief implementation definition 
 *  @author Umar Ba  , LoopFocus jUmarB@protonmail.com  
 */

#include <stdlib.h> 
#include <stdio.h> 
#include <errno.h>
#include <err.h>
#include <assert.h> 
#include <unistd.h>
#include <pthread.h>

#ifdef NAMEDSMPR 
#include <fcntl.h> 
#include <sys/stat.h> 
#endif  

#include "smphr.h"  
 

struct sem_agent_t  * configure  ( struct  sem_agent_t * agent , uint * count_limit )  
{ 
  errno = 0 ;
  agent->index =0  ; 
  uint lcount_until =  LCOUNT_UNTIL ; 
  if ( count_limit != _nullable ) 
  {
    lcount_until = *count_limit ; 
  }
  assert (lcount_until > 0  && "should be greater than zero  !") ; 
  agent->lm_counter = lcount_until ; 
#ifndef  NAMEDSMPR 
  agent->smphr_init =  sem_init  ; 
  agent->smphr_init(&agent->smphr_h ,  0 ,  0) ; 
  if (errno !=0) errx(errno ,  "cannot configure agent") ;
  
  agent->smphr_dist =  sem_destroy;
#else  
  //! not supported yet 
  agent->smphr_init = sem_open ; 
  agent->smphr_dist = sem_close ;
#endif
  
  return agent  ; 
}

void * count ( void * args  )  
{
  smphr_t * count_h =  (struct sem_agent_t *)  args ;  
   
  while ( 1 ) 
  {
     count_h->index++ ;  
     printf("%i\n" , count_h->index) ; 
     if  (count_h->index ==  count_h->lm_counter)  
     {
       sem_post(&count_h->smphr_h) ; 
     } 
     sleep(1) ; 
  }

  pthread_exit (_nullable) ; 
}

void *reset ( void * args  ) 
{
  smphr_t  * reset_h = (struct  sem_agent_t *) args ; 

  while ( 1 ) 
  {
     sem_wait(&reset_h->smphr_h);  
     reset_h->index = 0 ;  

  }

  pthread_exit(_nullable);
}
