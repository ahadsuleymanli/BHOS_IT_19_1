#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 250

struct Stack{
  int top;
  char arr[MAX_SIZE];
};

char pop(struct Stack* stack)
{
  if (stack->top == -1)
    return '\0';
  char val = stack->arr[stack->top];
  stack->top --;
  return val;
}

char peek(struct Stack* stack){
  if (stack->top == -1)
    return '\0';
  return stack->arr[stack->top];
}

bool isEmpty(struct Stack* stack)
{
  return stack -> top == -1;
}

bool push(struct Stack* stack, char val){
  if (stack->top == MAX_SIZE)
    return 0;
  stack->top ++;
  stack->arr[stack->top] = val;
  return 1;
}

bool isBalanced(struct Stack *stack, char *arr)
{
  for( int i = 0 ; arr[i]!='\0'  ; i++)
  {
    if (arr[i]=='(')	  
      push(stack,'(');
    else if ( arr[i] == ')' && peek(stack) == '(' )
      pop(stack);
    else if ( arr[i] == ')' && isEmpty(stack))
      return 0;
  }
  return isEmpty(stack);
}

int main()
{
  char brackets1[] = "(abcd(x))";
  char brackets2[] = "(abcd(x)))";
  char brackets3[] = "(((abcd(x)))";

  struct Stack stack;
  stack.top = -1;
  bool first = isBalanced(&stack, brackets1);

  bool second = isBalanced(&stack, brackets2);
  
  bool third = isBalanced(&stack, brackets3);
 
  printf("%d\n",first);
  printf("%d\n",second);
  printf("%d\n",third);
  return 0;
}
