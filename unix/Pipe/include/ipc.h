/** @file ipc.h 
 *  @brief Interprocess  channel   definition and proto
 *  @author  Umar Ba , LoopFocus Inc  ,jUmarB@protonmail.com 
 */ 

#pragma once 
#if !defined  (_interprocess_channel_h)
#define        _interprocess_channel_h

#define IPC 

/** NULL macro alias */  
#define  _nullable (void *) (0U << 1) 
#define  _Nullable _nullable 
#define  _void_0h  _Nullable

#define __noreturn  __attribute__((noreturn)) 


/** Interprocess channel between   processes */ 
#ifdef   IPC_FIFO  
  #ifndef    IPC_FIFO_FILENAME
    #define  IPC_FIFO_FILENAME  "ipc_fifo_tunnel.fifo"
  #endif
#else  
  /** when it 's a childprocess  created by fork*/ 
  #define IPC_FID  2 
  #define IPC_STDOUT_FN   (STDOUT_FILENO^1) 
  #define IPC_STDIN_FN    (STDIN_FILENO^1)
  #define IPC_CHILDP      (~0^~0) 
#endif 

#define  IPC_MAX_BUFFALWD  0xfe

/** Interprocess Channel error */
enum { 
  IPC_ERRINIT= -3,
};

/**  ipc  io  operation  perform */
enum { 
  IPC_WSTREAM, 
#define  IPC_WSTREAM  IPC_STDOUT_FN   
  IPC_RSTREAM, 
#define IPC_RSTREAM   IPC_STDIN_FN
} ; 

typedef  struct  __ipciofd ipciofd  ; 
struct  __ipciofd  { 
  int ipcwfd ; 
  int ipcrfd ;
};  


typedef struct  _prochannel_t pchan_t ; 
struct   _prochannel_t  {  
#if !defined (IPC_FIFO ) 
  int  fid[IPC_FID];
  struct __ipciofd  iofd; 
#else  

  int ipc_fifo_fd  ; 
#endif 
  char buffer[IPC_MAX_BUFFALWD] ;  
  void(*ipc_flush_buffer)(char *__restrict__  _internal_ipc_buffer,  size_t * ) ;
  
}; 


typedef  struct  __ipc_t ipc_t ; 


IPC static inline __noreturn void ipc_exit(int _ec ) { 
  _Exit(_ec) ;  
}

/** @fn  struct __ipc_t  * init ( struct __ipc_t * ) 
 *  @brief initialize  ipc 
 *
 */ 
IPC  struct  __ipc_t * init(struct __ipc_t * _ipctl) ;  

/**
 *
 */
IPC static  void bflush  ( char  *__restrict__  _buffer  ,  size_t * _buffer_size) ; 


IPC size_t ipc_io_operations(struct __ipciofd * ipciofd ,   char  * buffer , size_t  buffer_len  , int _operation_to_perform) ;  

 #endif /**  _interprocess_channel_h */ 
