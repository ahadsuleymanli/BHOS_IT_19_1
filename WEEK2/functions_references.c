#include "stdio.h"

//function prototypes


int swap1(int val1, int val2);

int swap2(int array[]);

void print(int *val1, int *val2);


int main(){

int i;
int j;
int array[5] = {1,2,3,4,5};

i = 10;
j = 15;

// printing indices, values, and memory locations
for (int i = 0 ; i<sizeof(array)/sizeof(int); i++ ){
  printf("array element %d: %d, location:%p\n",i, array[i], array+i);
}


printf("length of our array:%d\n",sizeof(array)/sizeof(int));



print(&i,&j);

// passes copies of i and j
swap1(i,j);
// original i and j do not change

print(&i,&j);

return 0;
}


// takes copies for val1 and val2
// swaps the copies of val1 and val2

int swap1(int val1, int val2){
  int temp;

  printf("inside swap function:\n");
  
//  print(&val1,&val2);
  
  temp = val1;
  val1 = val2;
  val2 = temp;

  printf("after swap:\n");
 // print(&val1,&val2);

  printf("exiting swap function:\n");
  return 999;
}


void print(int *val1, int *val2){
  
  printf("i:%d at %p\n",*val1, val1);
  printf("j:%d at %p\n",*val2, val2);
}



