#!/usr/bin/make 

CC = gcc
CFLAGS = -std=c99 -I -Wextra  -O2   -Wall   
exec = chstr 
HEADERS=$(wildcard  includes/*.h)  
SRC = $(wildcard *.c)  
OBJ = $(SRC:.c=.o) 

all : $(exec)

$(exec) : $(OBJ)  
	${CC} -o $@ $^  ${CFLAGS} 
	
charstr.o : $(HEADERS)  

%.o :  %.c
	$(CC)  -o  $@ -c  $<  $(CFLAGS) 


.PHONY : clean  mproper 

clean :  
	rm *.o

mproper: clean 
	rm  $(exec) 
