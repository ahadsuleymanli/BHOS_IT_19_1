## WEEK5: Structs, dynamic memory, dynamicly sized arrays, array based stack
This week we will start learning about data structures and their implementation using structs and arays.   
This week's material is from Modern C.

## Material:
### 1. ***const\*const*** pointers will be useful to you in reading this week's material from our alternate book Modern C   
int const * - pointer to const int   
int * const - const pointer to int   
int const * const - const pointer to const int   
```c
// pointer to const:
char *string1 = "string literal";       // pointer to a string literal, the pointed value is immutable meaning is not allowed to be changed.
string1[0] = 'x';                       // is undefined behavior, the compiler will allow it, but you risk a runtime error
char const* string2 = "string literal"; // pointer to a constant, compiler will not allow changes to the pointed value
string2[0] = 'x';                       // it will not compile and will ensure a safer code
string2 = string1;                      // is ofcourse allowed

// const pointer
int val1;
int val2;
int *const ptr1 = &val1;                // constant pointer, compiler will not allow changes to the pointer value
ptr1 = &val2                            // is used to disallow such operations, will not compile
*ptr1 = 10;                             // is allowed 

// const pointer to const
int const*const ptr1;                   // neither pointer value, nor the pointed value can be changed
```

### 2. ***Chapter 6.3 - 6.4 Structures, Chapter 13.1 - 13.2 Malloc***  
Supplementary [video on malloc](https://www.youtube.com/watch?v=lQP4X3odvHE)
### 3. ***Read this short [tutorial](https://www.tutorialspoint.com/cprogramming/c_command_line_arguments.htm) on command line arguments***

### 4. ***Data structures: Stacks***  
```
Stack is a data structure for "stacking" items one after another for later processing at a reverse order.
Can imagined as a resizable array where new elements are put at the end of the array.
Two or three functions are usually implemented for stacks push, pop and peek:
 - push adds new items, and pop removes the last element and returns it, peek returns the last element without removing it
Stack is a LIFO (last in first out) data structure.
```
## Stack implementation tutorial:

```c
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

// deallocates the dynamic memory to prevent memory leak
void deallocStack(struct Stack* stack) 
{ 
    free(stack->array);
    free(stack);
    printf("deallocated\n"); 
} 

int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 

void resize(struct Stack* stack) 
{
    stack->capacity *= 2;
    stack->array = (int*)realloc(stack->array,stack->capacity * sizeof(int));
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
  
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 
  
int main() 
{ 
    struct Stack* stack = createStack(); 
  
    push(stack, 10); 
    push(stack, 20); 
    push(stack, 30);
    push(stack, 40);

    printf("%d popped from stack\n", pop(stack)); 

    deallocStack(stack);
    return 0; 
} 
```
