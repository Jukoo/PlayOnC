#include  <stdio.h> 
#include  <stdlib.h>  
#include  "charops.h"

/**
 * char_strlen  
 * calculate the length of the string 
 * @params const char  *  
 * @return  int 
 */ 
extern int 
char_strlen (const char * charstr) {
    int char_count = 0; 
    char each_char = 0;
    do {
        char_count++ ; 
        each_char = charstr[char_count] ; 
    }while(each_char  != '\0') ;  
   
    return  char_count ;  
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
    // check the size str_dest in enought to get the contains
    // of str_source
    if ( !char_strlen(str_dest) >= char_strlen(str_source)) {
        fprintf(stderr , "failed  to copy contain  %c", 0xa) ; 
        perror("not enough  size"); 
        exit(EXIT_FAILURE);  
    }
 
    for(int each_char = 0 ; each_char < char_strlen(str_source) ; each_char++) {
        str_dest[each_char] =  str_source[each_char] ;    
    } 
    
    return   str_dest ;      
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

   int endless_pos = 0 ; 
   char endpoint   = 0 ; 
   do  {
       endpoint =  str_dest_cat[endless_pos] ; 
       endless_pos++ ; 
   }while(endpoint != '\0') ; 
   
   endless_pos-- ;    ///! end of the first word    

   for (int j  = 0 ; j <  char_strlen(str_src_cat) ;  j++ )  {
       str_dest_cat[endless_pos] = str_src_cat[j] ;
       endless_pos++;
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
    
    int  strcmp_status = 0 ; 
    for (int char_=0 ; char_ < char_strlen( char_str2)  ; char_++)  {

         if (char_str1[char_]  !=  char_str2[char_]) { 
            strcmp_status = 1  ; 
            break ; 
         }  
        
    }

    return  strcmp_status ; 
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
char_strrch(const char * char_str , char character)  {    

    char *char_str_args = NULL; 
    char single_char    = 0;

    for ( int  char_ = 0  ; char_  <  char_strlen(char_str); char_++)  { 
        single_char = char_str[char_] ;  
        if  (single_char ==  character)  {
            char_str_args  = &character ;  
            break  ;            
        }
    }
    
    return char_str_args != NULL ?  char_str_args  : NULL ; 
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
char_strbrk ( const char * char_str  , const char  * word_string)  {
    
    char  char_breaker       = 0    ;  
    char *char_breaker_index = NULL ; 

    for (  int i = 0 ;  i < char_strlen (char_str ) ;  i++ )  { 
        char_breaker =  char_str[i]  ; 
        if ( char_breaker  == word_string[i] )  {
            char_breaker_index =  &char_breaker   ; 
            break  ;            
        }    
    }

    return  char_breaker_index != NULL ?  char_breaker_index : NULL ;  
}

/*! 
 * char_strstr 
 * reach  a word  into  a string 
 * @param  const char * charstring 
 * @param  const char * word   
 * @return char *
 */
extern char *  
char_strstr  (const char * char_str ,  char const *  word )  { 
     
    int  word_size =  char_strlen(word) , size_watcher = 0   ;
    int status = 0 ;  
    char char_contains[MAX_CHAR_BUFFER] ;  
    
    int    i=0 , j=0 ; 
    while (  size_watcher <= word_size )  {
        
        if ( word[i] == char_str[j] )  {
             i++ ;  
             j++ ; 
             size_watcher++ ; 
        }else  {
            j++ ; 
        }
        if ( j >= char_strlen(char_str)) break  ; 
    } 
    
    if (size_watcher ==  word_size) {      
        for  ( int char_ =0  ;  char_ < size_watcher ; char_++ ) 
              char_contains[char_] =  word[char_] ;  
    }else  status = 1 ;   
    
    return   status  == 0 ? char_contains : NULL; 
}
