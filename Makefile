#!/usr/bin/make  

export   CC = cc 
export   CFLAGS  = -std=c99  -I  -Wextra  -Wall  -O2 -pedantic 

source_dir :=  libstring
exec_name  :=  string 
exec = $(source_dir)/$(exec_name)  

all   : $(exec)  

$(exec) :  
	@(cd $(source_dir)   &&  $(MAKE))  


.PHONY  : clean   mproper $(exec) 

clean  :  
	@(cd $(source_dir)   && $(MAKE) $@) 

mproper : 
	@(cd  $(source_dir)  && $(MAKE) $@ )   
