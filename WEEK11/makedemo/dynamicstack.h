#ifndef DYN_STACK
#define DYN_STACK

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

struct Stack* createStack();
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
void deallocStack(struct Stack* stack);

#endif