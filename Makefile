#!/usr/bin/make  

export CC = gcc 
export   CFLAGS  = -std=c99  -I  -Wextra  -Wall  -O2 
exec  =  charstr/chstr  


all   : $(exec)  

$(exec) :  
	@(cd charstr   &&  $(MAKE))  


.PHONY  : clean   mproper $(exec) 

clean  :  
	@(cd charstr  && $(MAKE) $@) 

mproper : 
	@(cd  charstr  && $(MAKE) $@ )   
