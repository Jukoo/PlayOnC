#ifndef LINKED_LIST  
#define LINKED_LIST 

#define FALLOC fprintf(stderr,"Fail allocation @ %i\n", __LINE__ )  

typedef struct  list { 
    int data ;  
    struct list  *next  ; 
} List ,*LIST ;  

typedef enum  { 
    FALSE , TRUE 
} BOOL  ; 

/*Check allocation memory  it 's all ok  */
static void * alloctrl ( void * ) ;  

/*Verify  if the list is not empty  */
static  BOOL  is_empty ( LIST list) ; 

/* Check if  List  has  a valid address */
static  void * CHECK ( LIST ) ;  

/* Instanciate   new list   if no initial number  given  
 * it automaticly  set to 0
 */
LIST  new_list ( int initial_number )  ;  

/* shit  new element
 * -(shift) 
 * |
 * v
 * [new_element]-> []->[]->[]-> (VOID *)0x0000000
 */
LIST shift ( List * list   , int  value )  ; 

/* push new element 
 *              (push) 
 *                 |
 *                 v
 * []->[]->[]->[]->[new element] -> (VOID *)0x0000000 
 */
LIST push ( List *list , int value ) ; 

/* unshift element  
 *         ^  (unshifted  element)  
 *         |
 *         |
 * ['llbeunshifted]->[]->[]->[]-> (VOID *) 0x0000000
 */
LIST unshift ( List *list )  ; 

/* pop element  
 *                  ^ (poped element) 
 *                  |
 *                  |
 * []->[]->[]->['llbepoped]-> (VOID *) 0x0000000
 */
LIST  pop (List *list  ) ;  

/* insert  new  node in the middle of the  list  by 
 * specifiying the index  or position 
 */ 
LIST insert ( LIST list ,  int value ,  size_t  position ) ; 

/* delete  node in specifique position  
 * by specifying node position 
 */
LIST delete ( List *  list ,size_t position) ;  

/**
 * release  each allocated block
 */
void release (LIST  list)  ; 

/*diplay all element of the list*/ 
void show (LIST  list ) ; 

/*calculate  the size of the list */  
size_t size (List* S)  ;  

#endif 
