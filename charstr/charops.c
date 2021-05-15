#include  <stdlib.h>
#include  <stdio.h> 
#include  <stddef.h> 

#include  "includes/charops.h"

/**
 * char_strlen  
 * calculate the length of the string 
 * @params const char  *  
 * @return  int 
 */ 
extern size_t  
char_strlen (const char * charstr) {
    int  i = 0  ; 
    for (;*charstr!='\0' ;charstr++ ,  i++ ) ; 
    return i  ; 
}

/**
 * char_strcpy 
 * just make a copy  
 * @param  char  the copy destination  
 * @param  const char  source 
 * @return  char*
 */
extern char *
char_strcpy(char * str_dest , const char * str_source) {

    size_t  word  = 0 ; 
    while ( *str_source != '\0') 
    {
        str_dest[word]  = *str_source ; 
        word++ ; 
        str_source++ ; 
    }
    return  str_dest ;     
}

/*!  
 * char_strcat 
 * concatenate char 
 * @param char  * destination 
 * @param const char * source 
 * @return char 
 */
extern char *
char_strcat (char * str_dest_cat , const  char * str_src_cat )  {
   
    if (  sizeof(str_dest_cat) >= char_strlen(str_src_cat) ) 
    {              
        fprintf(stderr ,  "Core dumped at  <%p>\n", str_dest_cat ) ; 
        return  (void*)0 ; 
    }
    char  *endpoint  =  ( str_dest_cat  +  char_strlen(str_dest_cat)) ;  

    while  ( *str_src_cat != 0  )  
    {
        *endpoint  =   *str_src_cat  ;  
        str_src_cat++  , endpoint++ ; 
    }
     
    return  str_dest_cat ; 
}

/* char_strcmp 
 * compare two strings
 * if they are identical  it return 0 
 * otherwise  it return 1 
 */
extern int
char_strcmp(const  char* char_str1 , const char * char_str2  ) {
    
    for ( ;*char_str1 !='\0'; char_str1++ , char_str2++) 
        if( *char_str1 !=  *char_str2)  
           return  EXIT_FAILURE  ;  

    return  EXIT_SUCCESS ; 
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
