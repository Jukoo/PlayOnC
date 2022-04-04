#include  <stdio.h> 
#include  <stdlib.h> 

#include "include/list.h" 


int main ( int argc , char **argv )  { 

    List *  list =  new_list(10) ;  
    list  = shift(list , 21) ;  
    list  = shift(list , 32) ;  
    list  = push (list  , 59) ; 
    list  = unshift(list) ; 
    //list  = pop(list) ;
    list   = insert(list ,  100 , 0) ;  

    //release(list) ; 
    list = delete(list , 1) ;   
    show(list) ; 
    size_t s  = size(list) ; 
    fprintf(stdout , "the size of the list is  %i\n" ,  s ) ; 

    return EXIT_SUCCESS ; 

} 
