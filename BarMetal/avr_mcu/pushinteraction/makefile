#!/usr/bin/make 

cc_toolchaine=avr-gcc  
board=atmega328p
program_platform_id=arduino 
serial=/dev/ttyUSB0 

cflags = -Wall -Wextra -O2 -DF_CPU=16000000UL -mmcu=$(board) 

src = $(wildcard *.c) 
obj = $(src:.c=.o)  

exec=btinteract.elf

all : $(exec) 
	

$(exec) : $(obj) 
	@echo -e "\t[ld] $^"
	$(cc_toolchaine) -o $@  $^ $(cflags) 

%.o : %.c 
	@echo -e "\t[cc] $<"
	$(cc_toolchaine) -o $@ -c $< $(cflags)  


.PHONY : clean  mproper hex_intel  flash 


hex_intel :  $(exec) 
	@echo -e "\t[HEX] intel"
	avr-objcopy  -O ihex  -R -eeprom   $^  $(exec:.elf=.hex) 


flash :  hex_intel 
	@echo -e  "\t [FLASH]" 
	avrdude -FV  -c $(program_platform_id)  -p $(board)  -P $(serial)  -U flash:w:$(exec:.elf=.hex) 


clean :  
	@echo -e "[CLS]" 
	rm *.o  
	

mproper : clean $(exec)  
	@echo -e "-------------"
	rm $(exec) 	
