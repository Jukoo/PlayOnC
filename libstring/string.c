#include  <stdlib.h>
#include  <stdio.h> 
#include  <stddef.h> 
#include  <assert.h> 

#include  "include/string.h"

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
    *dest_string++ = 0 ; 

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
 

    while  ( *++dest_string_concat )  ;  
    while  ( *source_string ) *dest_string_concat++=*source_string++ ;
    
    *dest_string_concat++=0 ; 
    
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
char_strrch(const  char * source_string   , char character)  {
    
    char *strsrc  = (char *) source_string  ; 
    while(*strsrc)
    {
        if  ( *strsrc++ == character )  
            return  strsrc ;  
    
    } 

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
char_strbrk (const  char * source_string   , const  char  * term_occurence  )  {

   char *clone_source_string  = (char * ) source_string ;  

   while ( *term_occurence)  
   { 
        
        if ( *term_occurence  ==   *source_string) 
            return  (char *) term_occurence; 
        
        if  (!*source_string ) 
        {
             source_string =  clone_source_string ;  
             term_occurence++ ;  
        }
        
        source_string++ ; 

   }

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
char_strstr  (const char *  haystack  ,  const  char *   needle )  { 
    
    char  *n_start  =  (char *)  needle; 

    size_t match=  0 ; 

    while ( *haystack )  
    {
       if (*haystack  == *needle)
       {
          needle++; match++;  
          if (!*needle)  
          {
              match++ ;
              size_t  needle_length =  needle - n_start ;
              if ( needle_length ==  match )    
                 return  ( char * ) haystack - needle_length ; 
             
          } 

       }else  match= 0 ; 

       haystack++ ;  
    }
    
    return   ( void *) 0 ; 
}
