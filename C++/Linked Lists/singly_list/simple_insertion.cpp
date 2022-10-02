#include <iostream>
using namespace std;
struct yogesh
{
  int value;
  struct yogesh *next;
};

void traverse_array(struct yogesh *ptr)
{
  while (ptr != NULL)
  {
    cout << "The data is : " << ptr->value << "\n";
    ptr = ptr->next;
  }
}

int main()
{
  struct yogesh *first = new yogesh;
  struct yogesh *second = new yogesh;
  struct yogesh *third = new yogesh;

  first->value = 1;
  first->next = second;

  second->value = 2;
  second->next = third;

  third->value = 3;
  third->next = NULL;

  traverse_array(first);
  return 0;
}