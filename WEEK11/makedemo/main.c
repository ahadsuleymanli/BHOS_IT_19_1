#include <stdio.h>
#include "dynamicstack.h"

int main()
{
  struct Stack* stack = createStack();
  push(stack, 10);

  push(stack, 11);
  push(stack, 12);
  push(stack, 13);
  push(stack, 14);
  push(stack, 15);

  printf("popped value: %d\n", pop(stack));
//
  printf("popped value: %d\n", pop(stack));
  printf("popped value: %d\n", pop(stack));
  printf("popped value: %d\n", pop(stack));
		  
  printf("popped value: %d\n", pop(stack));
  printf("popped value: %d\n", pop(stack));
  printf("popped value: %d\n", pop(stack));
  printf("popped value: %d\n", pop(stack));
  
  deallocStack(stack);
  return 0;
}