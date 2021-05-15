#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
 
#include "includes/charops.h"


int main  (int argc ,  char ** argv) {
    
    char *my_char_variable =  "no idea what im doing"  ;  
    
    // test of char_strlen  
    int size = char_strlen(my_char_variable) ; 
    ECHO_I("length of the string  is  ", size) ;  

    //fprintf (stdout , " length of the string is %d \n" , size) ; 

    //  test of char_strcpy  
    char cpy_of_my_char_variable[100]  = {0} ; 
    char_strcpy(cpy_of_my_char_variable , my_char_variable)  ; 
    fprintf (stdout , "source -> %s \ncopy dest =>  %s \n" , my_char_variable ,
             cpy_of_my_char_variable) ; 

    // test of  char_strcat 
    char concate_char_variable[100] ="i have " ; 
    char_strcat(concate_char_variable , cpy_of_my_char_variable) ; 
    ECHO_S("concatenate  -> ",  concate_char_variable) ; 
    //fprintf(stdout , "concatenat -> %s \n" , concate_char_variable) ;

    // test of  char_strcmp 
    char  word1[100] = "hey" , word2[]="hey" ; 

    int compare_status  =  char_strcmp (word1 , word2)  ;  
    fprintf(stdout , "compare status %d  line %d \n " ,  compare_status, __LINE__) ;
    // test of  char_strrch
    char string1[]  = "hi" ,  *char_looking_for = NULL  ; 
    char_looking_for =  char_strrch(string1 ,  'h' ) ; 
    
    if ( char_looking_for != NULL )  
        fprintf(stdout , "character founded  : %s \n", char_looking_for) ;  
    else  
        fprintf(stdout , "character not found  : %d \n", char_looking_for) ;  
    
    
    // test of char_strbrk 
    char *charbrk=  NULL  ; 
    charbrk = char_strbrk("salut" ,  "slx")  ; 
    if(charbrk != NULL)
        fprintf(stdout ,  "string char found  :%s \n" ,  charbrk) ; 
    else 
        fprintf(stdout , "string char not found  : %d \n", charbrk) ;

   
   // test  of char_strstr 
   char  text[] = "this is a test" , test[] ="test"  ; 

   char  *strstr_status = char_strstr(text , test) ;  
   
   fprintf(stdout  , "status code  char_strstr  : %d \n" , strstr_status) ; 
   fprintf(stdout  , "strstr_status value       : %s  \n" , strstr_status) ; 
   
    
    return  EXIT_SUCCESS  ; 
}
