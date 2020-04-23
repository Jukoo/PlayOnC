#!/usr/bin/make 

CC = gcc
CC_OUTPUT= -o  
CFLAGS = -std=c99 -I -Wextra 
exec = chstr 
SRC = $(wildcard * .c)  
OBJ = $(SRC:.c=.o) 

all : $(exec)

$(exec) : charstr.o charops.o
	${CC} -o $@ $^  ${CFLAGS} 
	
charstr.o : charops.h

%.o :  %.c
	$(CC)  -o  $@ -c  $<  $(CFLAGS) 

debug : charstr.c charops.c	
	$(CC) -g  $^ $(CFLAGS) -v 

.PHONY : clean  mproper 

clean :  
	rm *.o

mproper: clean 
	rm  $(exec)  a.out 
