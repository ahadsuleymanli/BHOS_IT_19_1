#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

#include "dynamicstack.h"
#define STACK_CAPACITY 2 


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

void deallocStack(struct Stack* stack) 
{ 
    free(stack->array);
    free(stack);
    printf("deallocated\n"); 
} 