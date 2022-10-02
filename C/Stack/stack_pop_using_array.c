#include <stdio.h>

void push(char element, char stack[], int *index, int capacity)
{
  if (*index == -1)
  {
    stack[capacity - 1] = element;
    *index = capacity - 1;
  }
  else if (*index == 0)
  {
    printf("The stack is already full. \n");
  }
  else
  {
    stack[(*index) - 1] = element;
    (*index)--;
  }
}
void pop(char stack[], int *index, int capacity)
{
  if (*index == -1)
  {
    printf("The stack is empty. \n");
  }
  else
  {
    printf("Element popped: %c \n", stack[(*index)]);
    if ((*index) == capacity - 1)
    {
      (*index) = -1;
    }
    else
    {
      (*index)++;
    }
  }
}
int main()
{
  int size = 4;
  char stackArray[size];
  int top = -1;
  push('a', stackArray, &top, size);
  printf("Element on top: %c\n", stackArray[top]);
  push('b', stackArray, &top, size);
  printf("Element on top: %c\n", stackArray[top]);
  push('c', stackArray, &top, size);
  printf("Element on top: %c\n", stackArray[top]);
  push('d', stackArray, &top, size);
  printf("Element on top: %c\n", stackArray[top]);
  pop(stackArray, &top, size);
  printf("Element on top: %c\n", stackArray[top]);
  pop(stackArray, &top, size);
  printf("Element on top: %c\n", stackArray[top]);
  pop(stackArray, &top, size);
  printf("Element on top: %c\n", stackArray[top]);
  pop(stackArray, &top, size);
  printf("Top: %d\n", top);
  pop(stackArray, &top, size);
  return 0;
}