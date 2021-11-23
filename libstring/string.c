#include  <stdlib.h>
#include  <stdio.h> 
#include  <stddef.h> 
#include  <assert.h> 

#include  "head/string.h"

/**
 * char_strlen  
 * calculate the length of the string 
 * @params const char  *  
 * @return  int 
 */ 
 
extern size_t 
char_strlen (const char * source_string) {
    
    char *str_start_point   = (char* ) source_string ;  
    while ( *++source_string) ; 

    return source_string - str_start_point;  
}

/**
 * char_strcpy 
 * just make a copy  
 * @param  char  the copy destination  
 * @param  const char  source 
 * @return  char*
 */
extern char *
char_strcpy(char * dest_string  , const char * source_string) {

    while (*source_string) 
    {
          *dest_string++= *source_string++; 
    }
    return  dest_string ;      
}

/*!  
 * char_strcat 
 * concatenate char 
 * @param char  * destination 
 * @param const char * source 
 * @return char 
 */
extern char *
char_strcat (char * dest_string_concat , const  char * source_string )  {
 
     
    char  *dest_string_endpoint =   (dest_string_concat   +  char_strlen(dest_string_concat) ) ;  

    while  ( *source_string)   
    {
        *dest_string_endpoint = *source_string++ ;  
        dest_string_endpoint++ ; 
    }
     
    return  dest_string_concat ; 
}

/* char_strcmp 
 * compare two strings
 * if they are identical  it return 0 
 * otherwise  it return 1 
 */
extern int
char_strcmp(const  char* source_string1 , const char * source_string2  ) {
    
    while(*source_string1)
    { 
        if (*source_string1++ !=  *source_string2++) 
        {
            return   *source_string1 >  *source_string2  ? \
                     *source_string1 -  *source_string2  : \
                     *source_string2 -  *source_string1; 
        }        
    
    }

    return   0 ; 
}


/* char_strrch 
 * research a char in a string  
 * on  success  it return a address of the  
 * charater founded  
 * on fail it return NULL 
 * @param  const char * char_string  
 * @param  char character  
 * @return char* 
 */ 
extern char* 
char_strrch(char * char_str , char character)  {
    
    for(;*char_str != '\0'; char_str++ )  
        if (  *char_str  == character )  
            return  char_str ; 

    return (void*) 0 ; ; 
}

/**
 * char_strbrk 
 * research  the first occurence founded  in string
 * return NULL on fail 
 * @param const char * 
 * @param const char *  
 * @return  char * 
 **/
extern char *
char_strbrk ( char * char_str  , char  * word_string)  {

    for(size_t w_pos = 0  ;*word_string !='\0' ; char_str++ , word_string++,w_pos++)
        if( *char_str  == *word_string)  
            return   &char_str[w_pos];

   return (void *) 0 ; 
}

/*! 
 * char_strstr 
 * reach  a word  into  a string 
 * @param  const char * charstring 
 * @param  const char * word   
 * @return char *
 */
extern char *  
char_strstr  (char * char_str ,  char *  word )  { 

    size_t  w_len  = char_strlen(word) , i = 0 ;  
    while( *char_str !=  '\0')
    {
        if ( *char_str  ==  word[i] ) i++ ; 
        else  i=0 ; 
        if ( i == w_len) return word  ;  
        char_str++ ; 
    }
   
    return   (void *) 0 ; 
}
