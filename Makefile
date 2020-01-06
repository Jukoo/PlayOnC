#!/usr/bin/make 

DEBUG =  yes  
CC = gcc
CC_OUTPUT= -o  
CFLAGS =-v -std=c99 -I -Wextra 
exec = chstr 
SRC = $(wildcard * .c)  
OBJ = $(SRC:.c=.o) 

#obj-m+=$(OBJ)
all : $(exec)
#all: 
#	make -C  /usr/lib/gcc/x86_64-linux-gnu/8/build M=$(PWD) modules # ${CC} -o $@ $^  ${CFLAGS} 
$(exec) : charstr.o charops.o
	${CC} -o $@ $^  ${CFLAGS} 
	


charstr.o : charops.h

%.o :  %.c
	$(CC)  -o  $@ -c  $<  $(CFLAGS) 

debug : charstr.c charops.c	
	$(CC) -g  $^ $(CFLAGS)

.PHONY : clean  mproper 

clean :  
	rm *.o

mproper: clean 
	rm  $(exec)  a.out 
