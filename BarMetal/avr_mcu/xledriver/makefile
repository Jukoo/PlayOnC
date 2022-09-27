#!/usr/bin/make 


cc =avr-gcc 
programmer_id=arduino
board =atmega328p
sources=$(wildcard *.c)   
objects=$(sources:.c=.o)
xflags :=	
cflags = -Wall -Wextra  -DF_CPU=16000000UL -mmcu=$(board)  -O2   $(xflags) 

avroc=avr-objcopy
avrdude=avrdude

bin_elf=xledriver_animation.elf  
bin_hex=$(bin_elf:.elf=.hex) 

all: $(bin_elf) 



$(bin_elf) : $(objects)  
	@echo -e "[ LINK ]  $^" 
	$(cc)  -o $@  $^ $(cflags) 


%.o : %.c 
	@echo -e "[ COMPILING ]  $<" 
	$(cc)  -c $<  -o $@  $(cflags)  


.PHONY  : clean  clear mproper  flash hex_intel 

hex_intel:  $(bin_elf) 
	@echo -e "[ HEX ] $^" 
	$(avroc)  -O ihex -R -eeprom   $^   $(bin_elf:.elf=.hex) 

flash  : hex_intel  $(bin_hex) 
	@echo -e "[ Flashing ] "
	$(avrdude) -FV  -c $(programmer_id)  -p $(board) -P /dev/ttyUSB0 -U flash:w:$(bin_hex)  


clean  :  $(objects)   
	rm  $(objects)  

mproper : clean  
	rm $(bin_elf)  $(bin_elf:.elf=.hex)  
