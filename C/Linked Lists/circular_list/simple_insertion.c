#include <stdio.h>
#include <stdlib.h>

struct yogesh
{
  int value;
  struct yogesh *next;
};

void traverse_list(struct yogesh *head)
{
  struct yogesh *ptr = head;
  do
  {
    printf("Element is : %d \n", ptr->value);
    ptr = ptr->next;
  } while (ptr != head);
}

int main()
{
  struct yogesh *first;
  struct yogesh *second;
  struct yogesh *third;
  struct yogesh *fourth;

  first = (struct yogesh *)malloc(sizeof(struct yogesh));
  second = (struct yogesh *)malloc(sizeof(struct yogesh));
  third = (struct yogesh *)malloc(sizeof(struct yogesh));
  fourth = (struct yogesh *)malloc(sizeof(struct yogesh));

  first->value = 1;
  first->next = second;

  second->value = 2;
  second->next = third;

  third->value = 3;
  third->next = fourth;

  fourth->value = 4;
  fourth->next = first;

  traverse_list(first);
  return 0;
}