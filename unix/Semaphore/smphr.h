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
#define  _void_0h  _nullable 

#define  LCOUNT_UNTIL 5 

#ifdef NAMEDSMPR 
#include <fcntl.h> 
#include <sys/stat.h>  
#define   NSF  "/temps" 
#endif 

typedef  unsigned int uint; 
typedef  int (*smprh_end) (sem_t *) ; 
typedef sem_t *  (*semop) (const char * , int , ... ) ; 


typedef  struct  sem_agent_t  smphr_t ; 

struct sem_agent_t { 
  uint lm_counter ;
  uint index ; 
  sem_t   *smphr_h ;
#ifndef  NAMEDSMPR
  int (*smphr_init)  ( sem_t * , int , uint ) ;  
#else  
  semop smphr_init; 
#endif
  smprh_end smphr_terminate ;   
} ; 

typedef struct  __semphr_t  sema_t  ; 

/** @fn struct sem_agent_t * configure ( struct sem_agent_t * , uint * ) 
 *  @brief configure or initialize sem_agent_t member 
 *  @param struct sem_agent_t * 
 *  @param uint aka unsigne int  limit count
 *  @return  struct  sem_agent_t * 
 */ 
struct sem_agent_t * configure  (struct  sem_agent_t * , uint * count_limit) ; 

/** @fn struct __semphr_t  * configure ( struct  __semphr_t *   , unit * cl )
 *  @brief  like above function  but _nullable possibility to pass  _void_0h  aka  (void *) 0  as value 
 *          for instance to check back  to return code 
 *  @param struct  __semphr_t   *  
 *  @param uint aka unsigne int  limit count
 *  @return  struct  __semphr_t  *  Should be deferent to _void_0h 
 */ 

struct __semphr_t * configure_sa( struct __semphr_t * __restrict__ new_sem_agent , uint *  ) ;


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
