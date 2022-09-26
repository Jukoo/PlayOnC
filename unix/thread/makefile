#!/usr/bin/make  

cc = cc
xflags=  
cflags=-Wall -Wextra  -pedantic -lpthread   $(xflags)   
src=$(wildcard *.c) 
obj=$(src:.c=.o) 
	
elfbin=threading 

all : $(elfbin) 
   

$(elfbin) : $(obj) 
	@echo -e "[ LD ] $^" 
	$(cc) -o $@ $^  $(cflags) 


%.o :%.c 
	@echo  -e "[ CC ] $<" 
	$(cc) -o $@ -c $<  $(cflags)  


.PHONY : clean  mproper 


clean : 
	rm  $(obj) 
	 

mproper :  clean 
	rm $(elfbin) 
