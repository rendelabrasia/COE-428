#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//This is to get the 3 functions from intStack.c
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
  int ch;
  int mainPop;

  while ((ch = getchar()) != EOF)
  {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;

   //This checks the input if ch == '<'
  else if(ch == '<')
   {
   
   //Then ch will be inserted an alphabet
   ch = getchar();

   //This if statement checks if the "ch" is an alphabet, then you push the character
	if(isalpha(ch))
      {
		push(ch); 
      }

   //This checks the if statement regarding when it starts with "/", the character will be popped out of the chain. Eg. <a><b></b> , the end result is <a>.
   //Thus valid,
   else if(ch == '/') 
     {
     ch = getchar();
     mainPop = pop();						 

  //If the pop does not equal to the top character, it will be non-valid. Eg. <a><b></a> (Error). 
  //Thus Non-Valid
    if(mainPop != ch)
	 {
          
	fprintf(stderr,"Non-Valid\n"); 
	 exit(1); 
	 }
	
  //Otherwise, it will be valid.
   else 
	{
	fprintf(stdout,"Valid\n"); 
	exit(0); 
	} 
   }
 }
}
  //This if and else if statements says that if the stack is empty, it is Valid, and if it is not empty it is Non-Valid.
	
    if(isEmpty()== 1) 
	{
		fprintf(stderr,"Since the stack is empty at the end, its Valid as no illegal tags have been found\n");
		exit(1);   
	}
    else if (isEmpty() == 0)
	{

      fprintf(stdout,"Since the stack has not been emptied by the popped method, it is Non-Valid\n");
 	  exit(0);   
    }   
   exit(0);
  }
