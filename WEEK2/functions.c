#include "stdio.h"

//function prototypes


int arrayAdder(int array[], int arraySize);

int main(){

int array[5]; 

//initialize
//this is illegal because re-definitions are not allowed in c:
//array[5] = {1,2,3,4,5};

// asigning array elements one by one
array[0] = 1;
array[1] = 2;

// assigning values to array programatically
for (int i = 0 ; i<sizeof(array)/sizeof(int) ; i++){
	array[i] = i+10;
}

// printing indices, values, and memory locations
for (int i = 0 ; i<sizeof(array)/sizeof(int); i++ ){
  printf("array element %d: %d, location:%p\n",i, array[i], array+i);
}


  printf("length of our array:%d\n",sizeof(array)/sizeof(int));


  printf("\n\narray adder result:%d",arrayAdder(array, sizeof(array)/sizeof(int)));




return 0;
}


//functions serve to abstract functionality
//abstraction means to hide it in a way
int arrayAdder(int array[], int arraySize){

  int result = 0;

  printf("inside arrayAdder, location of array:%p\n",array);
	
  for (int i = 0 ; i<arraySize; i++){
   result = result + array[i];
  }
  return result;
}

//functions have a return value
//
//functions have parameters
int adder(int int1, int int2){

  return int1+int2;

}

