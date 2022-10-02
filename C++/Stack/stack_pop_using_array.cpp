#include <iostream>
using namespace std;

void push(char element, char stack[], int *index, int capacity)
{
  if (*index == -1)
  {
    stack[capacity - 1] = element;
    *index = capacity - 1;
  }
  else if (*index == 0)
  {
    cout << "The stack is already full."
         << "\n";
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
    cout << "The stack is empty"
         << "\n";
  }
  else
  {
    cout << "Element popped: " << stack[(*index)] << "\n";
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
  cout << "Element on top: " << stackArray[top] << "\n";
  push('b', stackArray, &top, size);
  cout << "Element on top: " << stackArray[top] << "\n";
  push('c', stackArray, &top, size);
  cout << "Element on top: " << stackArray[top] << "\n";
  push('d', stackArray, &top, size);
  cout << "Element on top: " << stackArray[top] << "\n";
  pop(stackArray, &top, size);
  cout << "Element on top: " << stackArray[top] << "\n";
  pop(stackArray, &top, size);
  cout << "Element on top: " << stackArray[top] << "\n";
  pop(stackArray, &top, size);
  cout << "Element on top: " << stackArray[top] << "\n";
  pop(stackArray, &top, size);
  cout << "Top: " << top << "\n";
  pop(stackArray, &top, size);
  return 0;
}