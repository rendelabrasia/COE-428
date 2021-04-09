#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//This takes the method from the intHeap and intStack
extern int pop();

extern void push(int);

extern void addHeap(int);

extern int heapDelete();

extern void heapify(int);


int main(int argc, char * argv[])
{
   //These are the instance variable
   int value;

   int x = 0;

   int y = 0; 

   int z = 0;

   int begin = 0;

   int t = 0;

   int heapArray[100]; //heapArray size

  while (scanf("%d\n", &value) != EOF) 
   {
    fprintf(stderr, "READING INPUT: %d\n", value);

    heapArray[x++] = value;
   }

   while(begin < x) 
   {
    z = begin;

   for(y = begin; y < x; y++) 
   {
    if(heapArray[y] > heapArray[z]) 
     {
      z = y;
     }
   }

  t = heapArray[begin];  

  addHeap(heapArray[z]);

  heapArray[z] = t;
  
  heapArray[begin] = heapArray[z];
   
  begin++;
  }

  //Creates a new line
  fprintf(stderr, "\n");

  heapify(1);


  //For each x value, an item is deleted from heap and pushed to stack.  
    for(x = 0; x < begin; x++) 
     {
      push(heapDelete());
     }

  //Creates a new line
    fprintf(stderr, "\n");

   //The program pops the stack and prints each item producing the output
    for(x = 0; x < begin; x++) 
     {
      fprintf(stderr, "%d\n", pop());
     }
      
   exit(0);
  }
