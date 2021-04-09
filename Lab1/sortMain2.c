#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

// This code was identical from the sortMain with a few modifications to it. A mixture of sortMain and commandlinedemo was implemented to the code. 

int main(int argc, char * argv[])
{
     int num[100000]; /*Array of ints to sort*/
     int nNumItems; /*number of actual items in the array*/ 
     int i;

    if (argc == 1) {
    
     /*Data Numbers Test*/ 
     nNumItems = 4;
     num[0] = 10;
     num[1] = 20;
     num[2] = 30;
     num[3] = 40;

  printf("\n The original data arrays are being printed out chronologically:");

     mySort(num, nNumItems);
       for(i = 0; i < nNumItems; i++)
        {
         printf("\n%d\n", num[i]);
        }
    }

   else if (argc > 1) 
      {   
       nNumItems = argc-1;
 /*This code shows the data arrays being sorted*/
   for(i =1; i < argc; i++)
       {
		num[i-1] = atoi(argv[i]); //atoi stands for ASCII TO INTEGERS
       }
  
 printf("\n The data arrays picked by you are being printed out chronologically:");
   
  mySort(num,nNumItems); 
   for(i = 0; i < nNumItems; i++) { 
		printf("\n%d\n", num[i]); }
      }	
      exit(0);
     } 
