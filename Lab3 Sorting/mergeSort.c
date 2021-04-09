#include "mySort.h"

void merge(int arr[], int first, int middle, int last)
{
    int temp[MAX_SIZE_N_TO_SORT]; // Temporary array for sorting.
    int w,x,y,z,temp_value; // Index value of the array to keep track of location.
    w = first;
    x = middle;
    y = middle+1;
    z = last;
    temp_value = 0;

    //It will decide the bigger number among the elements and sort them in the right order from lowest to highest.
    while(w < x+1 && y < z+1)
    {
        if(myCompare(arr[w],arr[y]) < 0) {
            myCopy(&arr[w++],&temp[temp_value]) ;
        }
        else {
            myCopy(&arr[y++],&temp[temp_value]);
        }
        temp_value++;
    }
    
    // They will pick up the remaining elements in the code and put it in an array A[x....y].
    while(w < x+1) {
        myCopy(&arr[w++],&temp[temp_value++]);
    }
    while(y < z+1) {
        myCopy(&arr[y++],&temp[temp_value++]);
    }

    int i;
    for (i=0, w=first; w <= z; i++, w++) {
        mySwap(&arr[w],&temp[i]);
    }
}

void mySort(int array[], unsigned int first, unsigned int last)
{
    int middle;

    if (first < last)
    {
        middle = (first+last)/2;
        mySort(array, first, middle);
        mySort(array, middle+1, last);
        merge(array, first, middle, last);
    }
}

