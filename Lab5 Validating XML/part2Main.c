#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//This is to get the 3 functions from intStack.c
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
  //These are the 4 instance variables going to be used in this code.
  //The purpose of the x[26] is that there are 26 alphabets and we will put this into an array.
  int ch;
  int mainPop;
  int x[26] = {0};
  int y = 0;
  

  while ((ch = getchar()) != EOF)
  {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;

   //This checks the input if ch == '<'
  else if(ch == '<')
   {
   
   //Then ch will be inserted an alphabet
   int ch = getchar();

   //This if statement checks if the "ch" is an alphabet, then you push the character
   //The 97 numeric value comes from the Stack Overflow in order to instantiates the character 'a'. 
   //Subtracting 97 from ch "maps" the character to the array[] from 0 and 25.
	if(isalpha(ch))
      {
		push(ch); 
        int list =(int)ch-97;
        x[list]++;
      }

   //This checks the if statement regarding when it starts with "/", the character will be popped out of the chain. Eg. <a><b></b> , the end result is <a>.
   //Thus valid,
   else if(ch == '/') 
     {
     int ch = getchar();
     mainPop = pop();						 

  //If the pop does not equal to the top character, it will be non-valid. Eg. <a><b></a> (Error). 
  //Thus Non-Valid
    if(ch != mainPop)
	 {
          
	fprintf(stderr,"Non-Valid\n"); 
	 exit(1); 
	 }
	}    
   }
     //This if statements says that if the stack is empty, it is Valid.
     //The purpose of the for loop statement is to count how many times the tags have been popped in the code.
    if (isEmpty() == 1)
	{

      fprintf(stdout,"Since the stack is empty at the end, its Valid as no illegal tags have been found\n");
        for(y = 0;y<26; y++)
		{
		if(x[y]>0)
	    	fprintf(stdout,"%c \t %d \n",(char)(y+97), x[y] );
		}
      exit(0);   
    }   
  }
    //This if statements says that if the stack is not empty, it is Non-Valid.
    if(isEmpty()== 0) 
	{
		fprintf(stderr,"Since the stack has not been emptied by the popped method, it is Non-Valid\n");

		exit(1);   
	}
   exit(0);
  }

