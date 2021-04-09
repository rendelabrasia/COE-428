/**
 *  The functions in this module implement a Stack data structure
 *  of char pointers (aka "strings").
 *  
 *  NOTE: the stack is implemented as a fixed size array (size = 100).
 *  Consequently, no more than 100 strings can be pushed onto
 *  the Stack at any given time.
 */

// Implementation hints:
//   The 3 functions--push, pop and isEmpty--share information
//   about the array used to implement the stack and the index
//   of the "top" of the stack.
//
//   You may want to make these variables global...
//   ...but that would
//   be a mistake (because anyone using the module would have
//   to ensure that they did not use global variables with the
//   same names).
//
//   An alternative in C is a "static global".
//   If a global variable is qualified as "static", it is global only
//   within the source code file where it is declared.
//   In parituclar, it cannot conflict with any other global variable.
//
//  RECOMMENDATION:
//   Uncomment the following 2 lines and use these static globals!

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
static int top = 0;
static char * stack[100];
int isEmpty();

/**
 * pop() removes the top string on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value NULL ((char *) 0) is returned.
 */

char *  pop()
{
  char num;

 if(isEmpty()== 1) 
   {
      fprintf(stderr,"The Stack is Empty thus it is Non-Valid.\n");
      return -1;      
   } 
 else 
   { 
     num = stack[top]; 
     top = top -1;
     return num;     
   } 
}

/**
 *  push(thing2push) adds the "thing2push" to the top of the stack.
 *
 *  If there is no more space available on the Stack, an error
 *  message is printed to stderr.
 */
void push(char * thing2push)
{
 if(top == 100) 
   {  
     fprintf(stderr, "The Stack is Full thus it is Non-Valid.\n");   
   } 
 else 
   {   
    top= top + 1;
    stack[top] = thing2push; 
   }
}

/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
int isEmpty()
 {   
    if(top == 0){
		return 1;
	}
	return 0;
	}
  }
