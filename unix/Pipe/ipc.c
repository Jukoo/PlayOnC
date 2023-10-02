/** @file  ipc.c 
 *  @brief Interprocess channel implemantation 
 *  @author Umar Ba , LoopFocus Inc , jUmarB@protonmail.com
 */ 

#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <err.h> 
#include <unistd.h> 

#ifdef IPC_FIFO 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#endif 



#include "ipc.h" 
 


struct __ipc_t *  init (struct __ipc_t *  ipc_ctrl)  
{

  ipc_ctrl =   malloc(sizeof (struct _prochannel_t)) ; 

  pchan_t *  ipc_channel = (struct _prochannel_t *) ipc_ctrl ; //  just to avoid this  ->  ((pchan_t *)ipc_ctrl)->attr  

  ipc_channel->ipc_flush_buffer = bflush ; 
  ipc_channel->ipc_flush_buffer (ipc_channel->buffer , _nullable );  

#ifndef  IPC_FIFO  
  if (pipe(ipc_channel->fid) <=~0 ) 
    errx(IPC_ERRINIT , "ipc error : cannot create pipe") ;

  /**  short cut mapping ipc io  */
  ipc_channel->iofd.ipcrfd =ipc_channel->fid[IPC_STDOUT_FN] ;  
  ipc_channel->iofd.ipcwfd =ipc_channel->fid[IPC_STDIN_FN]  ;  
 
#else  
  /** create  FIFO special file for named pipe */
  if (mkfifo(IPC_FIFO_FILENAME , S_IWUSR|  S_IRUSR) <= ~0) 
    errx(IPC_ERRFIFO , "ipc error : cannot make a FIFO special file (as named pipe)") ; 

  memcpy(ipc_channel->pipe_ff ,  IPC_FIFO_FILENAME ,strlen(IPC_FIFO_FILENAME)) ;  
#endif 
  return  ipc_ctrl  ; 
}


static   void bflush(char *restrict buffer ,  size_t  *_buffer_size )
{
  if  (_buffer_size == _void_0h) 
    explicit_bzero(buffer,IPC_MAX_BUFFALWD); 
  else 
    explicit_bzero(buffer , *_buffer_size);
}


size_t ipc_io_operations(struct __ipc_t *  ipc ,  char *buffer, size_t  buffer_length,  int io_perform)  
{

  if ( ipc ==  _void_0h ) errx( ~9 , "ipc  no initialized "); 
   
  struct _prochannel_t * ipc_channel = (struct _prochannel_t *)ipc ; 

  struct __ipciofd  ipciofd  = ipc_channel->iofd ; 


  size_t  io_bytes ; 

  switch (io_perform) {
  
    case IPC_WSTREAM   :
#ifndef  IPC_FIFO  
      close(ipciofd.ipcrfd) ;
#else  
      char *pipstream_file_w= ipc_channel->pipe_ff ;
      ipciofd.ipcwfd =  open(pipstream_file_w ,  O_WRONLY) ; 
      if (ipciofd.ipcwfd <= ~0) 
      {
        errx(~1 , "ipc open : fail to  open pipe stream file") ; 
      }
#endif 
      io_bytes = write(ipciofd.ipcwfd,   buffer ,  buffer_length) ; 
    
#ifdef IPC_AC_IMDLY 
      close (ipciofd.ipcwfd) ; 
#endif 
      break ; 
  
    case IPC_RSTREAM : 

#ifndef  IPC_FIFO  
      close(ipciofd.ipcwfd) ;
#else  
      char *pipstream_file_r = ipc_channel->pipe_ff ;
      ipciofd.ipcrfd =  open(pipstream_file_r ,  O_RDONLY) ; 
      if (ipciofd.ipcrfd <= ~0) 
      {
        errx(~1 , "ipc open : fail to  open pipe stream file") ; 
      }

#endif
      io_bytes = read(ipciofd.ipcrfd,   buffer ,  buffer_length) ; 
      printf("<%i> :: <%s>", ipciofd.ipcrfd , buffer) ; 
    
#ifdef IPC_AC_IMDLY 
      close (ipciofd.ipcrfd) ; 
#endif 
      break ; 
    default: 
      errx(~io_bytes, "ipc io perform : no action taken ") ; 
  }
   


  return  io_bytes ; 
}
