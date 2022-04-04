#include <stdio.h> 
#include <stdlib.h>  

#include "include/list.h"  


static void * alloctrl ( void * whatever ) { 
    whatever   = malloc(sizeof(*whatever)) ; 
    if   (!whatever) 
    {
        FALLOC ; 
        exit(EXIT_FAILURE) ;  
    }
    
    return whatever ;  

} 

static  BOOL  is_empty ( LIST list )  {  
    
    return  list == (void *) 0 ;  
} 

static  void *   CHECK ( List * list )   {  
   if (!list) 
   { 
       FALLOC; 
       exit(EXIT_FAILURE); 
   } 
   
  return list  ;  
} 


LIST new_list ( int initial_number ) {  
    List  * first_node  =  alloctrl(first_node) ;   

    first_node->data  = initial_number << 0 ; 
    first_node->next    = (void *)0 ; 
    
    return  first_node ; 
}

LIST shift  (List *list ,  int new_element  )   {  
    (void)  CHECK(list) ; 
    List *new_node =  alloctrl(new_node);  
    (void) CHECK(new_node) ; 
    new_node->data = new_element ;  
    new_node->next =  list ;  
    
    return  new_node ; 
} 

LIST  push (List *list ,int value )   { 
    (void) CHECK(list) ; 
    List *new_node = alloctrl(new_node) ; 
    (void) CHECK(new_node); 
     
    new_node->data = value ; 
    List  *_  = list ; 
    List  *penultimate  = list  ;   
    while ( list != (void *)0x000000)  
    {   
        penultimate= list ;  
        list = list->next ;  
    }
    
    penultimate->next = new_node ; 
    new_node->next =  ( void *) 0x0000000 ;     

    return _ ; 
} 


LIST unshift  ( List *list )   { 
     (void ) CHECK(list) ;  
     List *head_node  = list ; 
     list = list->next ; 
     free(head_node); 
     head_node = (void * ) 0x0000 ;  
     
     return  list ; 
}

LIST pop ( List *list)   { 
    (void) CHECK(list) ; 
    
    List *checkpoint  = list ; 
    List *penultimate = list ; 
    while(list != ( void *  ) 0x0000 ) 
    {
        penultimate = list ; 
        list= list->next ; 
    }
    
    free(penultimate) ; 
    penultimate=  (void * ) 0x000000  ;  
    return  checkpoint ; 

}

LIST  insert ( List *list ,  int value ,    size_t position_index )   { 
    (void) CHECK(list) ; 
    List *new_node  =  alloctrl(new_node) ;

    new_node->data =  value ;  
    
    size_t  max_position_index  =  size(list) ;  
    if  (position_index > max_position_index  || position_index  < 0 )  
    {
        fprintf (stderr ,  "<%p>  out of range \n") ;  
        exit(EXIT_FAILURE) ;  
    }

    if  ( position_index == 0 )  
        return  shift( list , value) ;  
    
    if  (position_index  == max_position_index) 
        return   push(list , value)  ; 
    
    size_t  index  = 0 ;  
    List *node_iter =  list  ;  
    List *penultimate = list ; 

    while ( node_iter != ( void *) 0x000000) 
    {  
        index++; 
        if ( position_index ==  index  )   
        {
            List *node_step = node_iter->next ; 
            node_iter->next  =  new_node ; 
            new_node->next   =  node_step;  

            return list ;   
        }
        node_iter   =  node_iter->next  ;
        
    }

    return  ( void *)0  ; 
   
} 


LIST delete (List *list  ,  size_t position_index )  { 
    (void) CHECK(list)  ; 

    size_t  max_posind  =  size(list) ;  
    if ( position_index >  max_posind )   
    {
        fprintf(stderr ,  "<%p>  out of range\n") ;  
        exit ( EXIT_FAILURE) ;  
    }

    if  ( position_index ==  0 ) 
        return unshift(list) ; 

    if  (position_index == max_posind) 
        return  pop(list) ; 

   
    size_t i = 0 ; 
    while ( list != ( void *) 0x00000) 
    {
        i++ ; 
        List *prenode  = list ;  
        if (  i ==  position_index ) 
        {
            List *target_node =   prenode->next ; 
            prenode->next  =prenode->next->next ;    
            free(target_node) ; 
            target_node =  (void *) 0x0000 ;  
            return list  ; 
        }
        
        list  = list->next ;
    }
    
    return  ( void *)0x000; 
}

void  release ( LIST list )  {  
    
    if (is_empty(list)) 
    {
        fprintf ( stdout ,  "List <%p> is Empty\n")  ; 
        return  ; 
    }
   
    List *node_iter = list  ; 
    while ( node_iter  != (void *)0 ) 
    {
        List * current_node  =  node_iter  ;  
        node_iter =  node_iter->next ;  
        free(current_node) ; 
        current_node = (void *) 0 ;  
    }

    show(node_iter);  

} 

void show (LIST list )  { 
    
    if(!list)
    {
        fprintf(stdout , "Nothing to show  @ <%p>\n", list) ; 
        exit(EXIT_FAILURE) ;  
    }

    List *node_iter  = list ;  

    while ( node_iter != (void*)0 ) 
    {
        fprintf ( stdout , "[ %i ] -> ", node_iter->data ) ;  
        node_iter =  node_iter->next ; 
    }
    
    puts("NULL") ;  
    
}

size_t  size (  List * list )  {  

    if  ( !list)
    {
        fprintf (stdout , "<%p>\n" ) ;
        exit(EXIT_FAILURE) ;  
    }

   size_t  size = 0 ; 
   while ( list != ( void *)0) 
   {
       size++ ; 
       list  = list->next ;  
   }

   return  size ; 
} 
