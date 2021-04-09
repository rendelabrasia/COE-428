#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "towers.h"

int main(int argc, char **argv)
{
  //Instance variables for the Tower Of Hanoi
    int n;
    int from;
    int dest;

    /*NOTE: There are 3 behaviours depending on the arguments given on the command line. What we need are no arguments, one argument, and three arguments.
           We cannot have more than 3 arguments and less than no arguments !(argc > 4, argc < 1) and it cannot be 2 arguments (argc != 3).*/ 

    //No arguments 
    if(argc == 1) 
    
    {
    n = 3;
    from = 1;
    dest = 2;
    towers(n, from, dest);
    }

    //One argument
    if(argc == 2)

    { 
    n = atoi (argv[1]);
    from = 1;
    dest = 2;
    towers(n, from, dest);
    }

    //Three arguments
    if(argc == 4)
    
    {
    n = atoi (argv[1]);
    from = atoi (argv[2]);
    dest = atoi (argv[3]);
    }

       /*These are the restrictions for the Tower of Hanoi. They were put in comments since they are only additional informations and are good to know for the code. 
     if (n < 0)
     {
        fprintf (stderr, "There cannot be negative disks.");
        exit (1);
     }
   

     if (from <= 0)
     {
        fprintf (stderr, "The From values cannot have a negative or a zero value.");
        exit (1);
     }


     if (dest <= 0)
     {
        fprintf (stderr, "The Dest values cannot have a negative or a zero value.");
        exit (1);
     }

     if (from > 3  dest > 3)
     {
        fprintf (stderr, "The number can only be between 1 and 3 Towers for From and Dest based on the requirements.");
        exit (1);
     }

     if (from == dest)
     {
        fprintf (stderr, "The From values cannot be the same as the Dest values.");
        exit (1);
     }*/


    exit(0);
}
