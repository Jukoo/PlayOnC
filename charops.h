#ifndef  CHAR_OPS
#define  CHAR_OPS


#define  ECHO_S(words , argstr) fprintf(stdout ,"%s  %s  - >  Line  %d  %c" , words, argstr, __LINE__,0x00a )
#define  ECHO_I(words , argint) fprintf(stdout ,"%s  %d  - >  Line  %d  %c" , words, argint, __LINE__,0x00a )



extern int   char_strlen (const char *)                ; 
extern char *char_strcpy (char * , const char  *)      ; 
extern char *char_strcat (char * , const char  *)      ;
extern int   char_strcmp (const char * , const char *) ; 
extern char *char_strrch (const char * , char)         ; 
extern char *char_strbrk (const char * , const char *) ;
extern char *char_strstr (const char * ,const char *) ;  

#endif 
