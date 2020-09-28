```c
#include "stdio.h"
void swapArrays(int a1[], int a2[], int len);           
void print2DArr(int *arr2D[], int rows, int columns);

int main(){
    int a1[] = {1,2,3,4,5};
    int a2[] = {0,0,0,0,0};
    int len = sizeof(a1)/sizeof(int);
    int *arr2D[2] = {a1,a2};            // a 2 length array of int pointers, 
                                        // remember an int pointer pointing to [0] of an array 
                                        // is all you need to point to an array
    print2DArr(arr2D, 2, len);
    swapArrays(a1, a2, len);
    print2DArr(arr2D, 2, len);
    return 0;
}
void swapArrays(int a1[], int a2[], int len){
    // swaps contents of arrays
}
void print2DArr(int *arr2D[], int rows, int columns){
    // prints contents of the 2D array in a flattened shape
    // eg: [[1,2],[3,4]] will be printed as 1 2 3 4\n
    // make sure there is no empty ' ' printed after the last element
}  

```

### Due date:  
***Tuesday 6th***