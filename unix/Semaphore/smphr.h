/** @file  smphr.h 
 *  @brief data  structure and prototype definition 
 *  @author Umar Ba LoopFocus jUmarB@protonmail.com 
 */

#pragma once 
#if !defined (smphr)
#define  smphr

#include <semaphore.h> 

#define  _nullable (void * )( 0U << 1 )  
#define  _Nullable  _nullable  

#define  LCOUNT_UNTIL 5  

typedef  unsigned int uint; 

typedef  struct  sem_agent_t  smphr_t ; 
struct sem_agent_t { 
  uint lm_counter ;
  uint index ; 
  sem_t   smphr_h ;
#ifndef  NAMEDSMPR
  //! when you're not using  named semaphore 
  int (*smphr_init)  ( sem_t * , int , uint ) ;  
  int (*smphr_dist)  ( sem_t * ) ; 
#else  
  sem_t *(*smphr_init) (const char * ,  int) ; 
  int (*smphr_dist)   (sem_t *) ;  
#endif 
} ; 

/** @fn struct sem_agent_t * configure ( struct sem_agent_t *  , uint * ) 
 *  @brief configure or initialize sem_agent_t member 
 *  @param struct sem_agent_t * 
 *  @param uint aka unsigne int  limit count
 *  @return  struct  sem_agent_t * 
 */ 
struct sem_agent_t * configure  (struct  sem_agent_t * , uint * count_limit) ; 

/** @fn  void  * count ( void * args ) 
 *  @brief thread routine  that just increment value  
 *  @param void * args 
 *  @return  void * 
 */ 
void * count  ( void * args ) ; 

/** @fn  void * reset ( void * args ) 
 *  @brief thread routine that reset value to 0  
 *  @param void  * args  
 *  @return  void *  
 */ 
void * reset  ( void * args ) ; 



#endif /** smphr */ 
