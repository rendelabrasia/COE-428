#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
{
    int i;
    int j;
    int temp_value;

    for (j=first; j<=last; j++)
    {
        temp_value=array[j];
        i=j-1;

        while (i>=0 && myCompare(array[i], temp_value)>0) // myCompare function returns a negative number if and only if x < y. 
        {
            mySwap(&array[i+1], &array[i]); // mySwap function interchange the elements array[i+1] and array[i].
            i=i-1;
        }
        myCopy(&temp_value, &array[i+1]); //myCopy function keeps in track of the position of individual data elements.
    }
}
