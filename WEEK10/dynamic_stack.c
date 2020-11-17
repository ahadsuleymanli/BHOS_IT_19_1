#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

#define STACK_CAPACITY 2 

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

struct Stack* createStack() 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = STACK_CAPACITY; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 

int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
}

int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 

void arrcpy(int *source, int *target, int size)
{
    for(int i = 0 ; i<size ; i++)
        target[i] = source[i];
}

void resize(struct Stack* stack) 
{
    int oldCapacity = stack->capacity;
    stack->capacity *= 2;
    int* tmpArray = (int*)malloc(stack->capacity * sizeof(int));
    arrcpy(stack->array, tmpArray, oldCapacity);
    free(stack->array);
    stack->array = tmpArray;
    printf("stack reallocated, new length: %d\n",stack->capacity);
} 

void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        resize(stack);
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
}

int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
}

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

  printf("popped value: %d\n", pop(stack));
  printf("popped value: %d\n", pop(stack));
  printf("popped value: %d\n", pop(stack));
		  
  printf("popped value: %d\n", pop(stack));
  printf("popped value: %d\n", pop(stack));
  printf("popped value: %d\n", pop(stack));
  printf("popped value: %d\n", pop(stack));

  return 0;
}
