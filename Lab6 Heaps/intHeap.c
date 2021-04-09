#include <stdio.h>
#include <stdlib.h>

/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

//This shows the heap array size
static int heap[100]; 

//This initialize the size to 0
static int size =0;

//This initialize the top of the stack to 1
static int top = 1;

//This initialize the bottom of the stack to 1
static int bottom = 1;

//This represents the max heapify of the code
void heapify (int i)
{
  if(i <= heapSize()) 
 {
  fprintf(stderr, "<node id=\"%d\">", heap[i]);

  heapify(2*i);

  heapify(2*i + 1);

  fprintf(stderr, "</node>");   
 }
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */
int heapDelete()
{
    int delete;

	delete = heap[heapSize()];

	size--;

	return delete;
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
  
   heap[top++] = thing2add;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return top-bottom;  //A dummy return statement
}
