#if !defined  CHARSTRING_H  
#define       CHARSTRING_H

#define  ECHO_S(words , argstr) fprintf(stdout ,"%s  %s  - >  Line  %d  %c" , words, argstr, __LINE__,0x00a )
#define  ECHO_I(words , argint) fprintf(stdout ,"%s  %d  - >  Line  %d  %c" , words, argint, __LINE__,0x00a )
 
#define   MAX_CHAR_BUFFER  0X03E8 


/*!
 * char_strlen : calculate the length of the string
 * @params const char  *
 * @return  int
 */
extern size_t  char_strlen (const char * __source_string)  ; 


/*!
 * char_strcpy 
 * just make a copy  
 * @param  char  the copy destination  
 * @param  const char  source 
 * @return  char*
 */
extern char *char_strcpy (char *__dest_string   , const char  * __source_string)  ; 

/*!
 * char_strcat
 * concatenate char
 * @param char  * destination
 * @param const char * source
 * @return char
 */
extern char *char_strcat (char *__dest_string_to_concat , const char  *__source_string)      ;

/*!
 * char_strcmp 
 * compare two strings
 * if they are identical  it return 0 
 * otherwise  it return 1 
 */
extern int   char_strcmp (const char *__source_string1 , const char * __source_string2) ; 


/*!
 * char_strrch
 * research a char in a string
 * on  success  it return a address of the
 * charater founded
 * on fail it return NULL
 * @param  const char * char_string
 * @param  char character
 * @return char*
 */
extern char *char_strrch (char *__source_string  , char  __character)         ; 
    

/*!
 * char_strbrk
 * research  the first occurence founded  in string
 * return NULL on fail
 * @param const char *
 * @param const char *
 * @return  char *
 **/
extern char *char_strbrk (char *  __source_string ,char *__term_occurence) ;

/*!
 * char_strstr
 * reach  a word  into  a string
 * @param  const char * charstring
 * @param  const char * word
 * @return char *
 */
extern char *char_strstr (char * __source_string  ,char * __needle)  ;  

#endif 
