#!/usr/bin/make 

CC     =  cc  
CFLAGS = -std=c99 -I -Wextra  -O2   -Wall  -pedantic  
exec   = string
default_header:= include 

HEADERS=$(wildcard  $(default_header)/*.h)  
SRC = $(wildcard *.c)  
OBJ = $(SRC:.c=.o) 

all : $(exec)

$(exec) : $(OBJ) 
	@echo -e "\t[ LD ] " $^
	@${CC} -o $@ $^  ${CFLAGS} 
	
main.o: $(HEADERS)  

%.o :  %.c
	@echo  -e "\t[ CC ]" $<
	$(CC)  -o  $@ -c  $<  $(CFLAGS) 


.PHONY : clean  mproper 

clean :  
	rm *.o

mproper: clean 
	rm  $(exec) 
