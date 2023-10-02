#include<stdlib.h> 
#include<stdio.h> 
#include<string.h>
#include <err.h> 

#include <unistd.h> 
#include <fcntl.h> 

#define IPC_FIFO 
#include "ipc.h"

int 
main () 
{

  char *pipe_file =  "ipc_chain.fifo"; 
  char mesg[0xff] = {0} ;  

  struct __ipc_t * ipc_reader = init(_void_0h) ; 
  if ( ipc_reader == _void_0h  ) 
    errx(1, "ipc init reader error")  ;  

  int fd = open( pipe_file , O_RDONLY ) ;  

  read(fd, mesg  ,  0xff) ; 

  close(fd) ; 
  printf("-> %s " , mesg) ; 


  return  EXIT_SUCCESS; 
}
