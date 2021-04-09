#include <stdlib.h>
#include <stdio.h>

/* The purpose of this lab is to make sure that the 6 Commands Work:
 No Commands, One/Zero Commands, Print Command, Change Command, Garbage Identify Command, and Delete Command.

 No Command's purpose: Print out the Starting State before any commands are called upon.
           Example: Starting State C.   

 One/Zero Command's purpose: To make sure when starting in the starting state, calling upon 
                             the input to 0 or 1 can change state for the machine with its respected variable name.
           Example: When C goes to 1, it becomes E, then goes to 1, it becomes D, then goes to 0, and it becomes B.

 Print Command's purpose: Print out all the states available in the program which is your State Machine combination. This is done by invoking the letter 'p'. 
           Example:  Rendel's Customized State Machine.
                                 A B C
                                 B H C
                                 C C E
                                 D B H
                                 E F D 
                                 F D A 
                                 G A B 
                                 H G F 
                 Second Column states when the input goes to 0
                 Third Column states when the input goes to 1

 Change Command's purpose: Changes the present state to the next state when invoked by the letter 'c' then by a '1' or '0' followed by the initial state.

 Garbage Identify Command's purpose: Identify all states that are reachable or unreachable from the current state.
                                     If all states are reachable, it should output No garbage otherwise it will collect the garbage by invoking 'g'.

 Delete Command's purpose: Empties the garbage by invoking 'd'. */
 


//The use of typedef is to make the code cleaner and more organized by not writing the struck all the time.
//Instance Variables are being declared in this section.
//stateNum also indicates the number in the array. 
typedef struct rendelStateMachine 
{
 char stateName;

 int variable;

 int stateNum;

 struct rendelStateMachine*next_state_0;

 struct rendelStateMachine*next_state_1;
} 


finiteStateMachine; 

//Indicates the number of states in the array, in this case there are 8 from [A,B,C,D,E,F,G,H].
finiteStateMachine states[8];


//Since we know now that there are 8 variables inside the array, we will indicate that 0 is the first number and 7 is the last number. 
//The same meaning: 0 = A, 1 = B, 2 = C, 3 = D, 4 = E, 5 = F, 6 = G, 7 = H.   
void initialStates() 
{
//Starting from A to H
//The code gives order to what the variable will hold.

//Current State: A
 states[0].stateName = 'A';

 states[0].stateNum = 0;

 states[0].next_state_0 = states + 2; //This will indicate that State A will go to State C at input 0.

 states[0].next_state_1 = states + 6; //This will indicate that State A will go to State G at input 1.
	 
//Current State: B
 states[1].stateName = 'B';

 states[1].stateNum = 1;

 states[1].next_state_0 = states + 7; //This will indicate that State B will go to State H at input 0.

 states[1].next_state_1 = states + 2; //This will indicate that State B will go to State C at input 1.
	 
//Current State: C
 states[2].stateName = 'C';

 states[2].stateNum = 2;

 states[2].next_state_0 = states + 2; //This will indicate that State C will go to State C at input 0.

 states[2].next_state_1 = states + 4; //This will indicate that State C will go to State E at input 1.
	 
//Current State: D
 states[3].stateName = 'D';

 states[3].stateNum = 3;

 states[3].next_state_0 = states + 1; //This will indicate that State D will go to State B at input 0.

 states[3].next_state_1 = states + 7; //This will indicate that State D will go to State H at input 1.
	 
//Current State: E
 states[4].stateName = 'E';

 states[4].stateNum = 4;

 states[4].next_state_0 = states + 5; //This will indicate that State E will go to State F at input 0.

 states[4].next_state_1 = states + 3; //This will indicate that State E will go to State D at input 1.
 
//Current State: F
 states[5].stateName = 'F';

 states[5].stateNum = 5;

 states[5].next_state_0 = states + 3; //This will indicate that State F will go to State D at input 0. 

 states[5].next_state_1 = states + 0; //This will indicate that State F will go to State A at input 1.
 
//Current State: G
 states[6].stateName = 'G';

 states[6].stateNum = 6;

 states[6].next_state_0 = states + 0; //This will indicate that State G will go to State A at input 0.

 states[6].next_state_1 = states + 1; //This will indicate that State G will go to State B at input 1.
	 
//Current State: H
 states[7].stateName = 'H';

 states[7].stateNum = 7;

 states[7].next_state_0 = states + 6; //This will indicate that State H will go to State G at input 0.

 states[7].next_state_1 = states + 5; //This will indicate that State H will go to State F at input 1.	 

}

//The code's function in here is to print the Customized State Machine Table that was given in the lab manual.
//The use of fprintf is to print the string in the file.
void printCommand()
  {
     int i=0;
     for(i =0; i <8; i++)
     {
     if(states[i].variable!= 2)
     {
     fprintf(stdout, "%c %c %c\n", states[i].stateName, states[i].next_state_0->stateName, states[i].next_state_1->stateName);
     }
     }
  }

int main(int argc, char * argv[])
{

   int x=0;

   int y=0;

   char commands[2]; //This will be used for taking commands passed in the array.

   initialStates();

   finiteStateMachine currentState = states[2]; //This is done in order to show that the Starting State for this Lab is C. 

   //This will be shown in the start of the terminal.  
   fprintf(stdout, "Enter a command \n"); 

   // This will print out the Starting State for this Lab which is C.
   fprintf(stdout, "The Starting State: %c \n", currentState.stateName);

//This while loop code will scan the input of the code.
while(y != 1)
{
  
  for (x=0; x<=4;x++)
   {
	scanf("%c",&commands[x]);
 
  if (commands[x] == '\n')
   {
      
     printCommand();
	
     break;
   }
}
    //This code is to show the Zero's command and see what the output will get when it is invoked by '0'.
	  if(commands[0] == '0')
      {
	    fprintf(stdout, "%c\n",currentState.next_state_0-> stateName);

		currentState = states[currentState.next_state_0-> stateNum];
	  }
	  
	//This code is to show the One's command and see what the output will get when it is invoked by '1'.
	  if(commands[0] == '1')
      {
	    fprintf(stdout, "%c\n",currentState.next_state_1-> stateName);

		currentState = states[currentState.next_state_1-> stateNum];
	  }
	  
	  //There is an escape function made in order to stop running the program. This is done by invoking 'e'.
	  if(commands[0] == 'e')
      {
	     y =1;

		 break;
	  }
  }
    
    //This code is used for printing the outputs and is done so by invoking 'p'. 
    if(commands[0] == 'p')
      {
	     printCommand();
	  }

    //This change command code is for the change for zero
    //This is done so by invoking 'c' before the start of the input.
    //This is also done by adding a '0' in front of c then followed by its initial states going forward.
	if(commands[0] == 'c')
    {

    if(commands[2] == '0')
      {
	
    if(commands[4] == 'A')
      {
	  currentState.next_state_0 = states;
		   
      states[currentState.stateNum].next_state_0 = states;
      }	
    
    else if(commands[4] == 'B')
      {
      currentState.next_state_0 = states+1;

	  states[currentState.stateNum].next_state_0 = states+1;
      }

    else if(commands[4] == 'C')
      {
	  currentState.next_state_0 = states+2;
		   
      states[currentState.stateNum].next_state_0 = states+2;
      }
   
    else if(commands[4] == 'D')
      {
	  currentState.next_state_0 = states+3;
	
	  states[currentState.stateNum].next_state_0 = states+3;
      }
           
    else if(commands[4] == 'E')
      {
	  currentState.next_state_0 = states+4;
		   
      states[currentState.stateNum].next_state_0 = states+4;
      }
         
    else if(commands[4] == 'F')
      {
	  currentState.next_state_0 = states+5;
		
      states[currentState.stateNum].next_state_0 = states+5;
      }
           
    else if(commands[4] == 'G')
     {
     currentState.next_state_0 = states+6;
		   
     states[currentState.stateNum].next_state_0 = states+6;
     }	
           
    else if(commands[4] == 'H')
     {
	 currentState.next_state_0 = states+7;

     states[currentState.stateNum].next_state_0 = states+7;
      }		   
	}  
	}

	//This change command code is for the change for one
    //This is done so by invoking 'c' before the start of the input.
    //This is also done by adding a '1' in front of c then followed by its initial states going forward.
	if(commands[0] == 'c')
     {

	if(commands[2] == '1')
     {
	       
    if(commands[4] == 'A')
     {
	 currentState.next_state_1 = states;

     states[currentState.stateNum].next_state_1 = states;
     }
	
     else if(commands[4] == 'B')
     {
	 currentState.next_state_1 = states+1;

	 states[currentState.stateNum].next_state_1 = states+1;
     }
           
     else if(commands[4] == 'C')
     {
	 currentState.next_state_1 = states+2;

	 states[currentState.stateNum].next_state_1 = states+2;
     }
           
     else if(commands[4] == 'D')
     {
     currentState.next_state_1 = states+3;
		   
     states[currentState.stateNum].next_state_1 = states+3;
     }
           
     else if(commands[4] == 'E')
     {
	 currentState.next_state_1 = states+4;
		   
     states[currentState.stateNum].next_state_1 = states+4;
     }
           
     else if(commands[4] == 'F')
     {
     currentState.next_state_1 = states+5;

	 states[currentState.stateNum].next_state_1 = states+5;
     }

     else if(commands[4] == 'G')
     {
	 currentState.next_state_1 = states+6;
	
	 states[currentState.stateNum].next_state_1 = states+6;
     }	
           
     else if(commands[4] == 'H')
     {
     currentState.next_state_1 = states+7;
	
 	 states[currentState.stateNum].next_state_1 = states+7;
     }		   
	}  
   }
  exit(0);
 }
