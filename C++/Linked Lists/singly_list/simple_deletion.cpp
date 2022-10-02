#include <iostream>
using namespace std;
struct yogesh
{
  int value;
  yogesh *next;
};

void traverse_array(yogesh *ptr)
{
  while (ptr != NULL)
  {
    cout << ptr->value;
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

  cout << "Array before Deletion "
       << "\n";
  traverse_array(first);
  first->next = third;
  delete second;
  cout << "\nArray After Deletion"
       << "\n";
  traverse_array(first);
}