#include "stdio.h"

int main(void){
int i;
i = 10;
int j = 10;

int* ptr;

printf("ptr:%p, address:%p\n",ptr,&ptr);

printf("i:%d, address:%p\n",i,&i);

printf("j:%d, address:%p\n",j,&j);


printf("round1");
ptr = &i;		// asigning pointer value to address of i
*ptr = *ptr + 10;	// dereferencing pointer and modifying the variable


printf("ptr:%p, address:%p\n",ptr,&ptr);

printf("i:%d, address:%p\n",i,&i);

printf("j:%d, address:%p\n",j,&j);


printf("round2");
ptr = &j;
*ptr = *ptr*10 + 5;


printf("ptr:%p, address:%p\n",ptr,&ptr);

printf("i:%d, address:%p\n",i,&i);

printf("j:%d, address:%p\n",j,&j);




return 0;

}
