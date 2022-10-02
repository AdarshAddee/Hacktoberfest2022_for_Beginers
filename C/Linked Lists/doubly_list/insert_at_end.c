#include <stdio.h>
#include <stdlib.h>

struct yogesh
{
  int value;
  struct yogesh *previous;
  struct yogesh *next;
};

void insertEnd(struct yogesh *last, int data)
{
  struct yogesh *a = (struct yogesh *)malloc(sizeof(struct yogesh));
  a->value = data;

  a->next = NULL;
  a->previous = last;
  last->next = a;
  last = a;
}

void traverse_list_forward(struct yogesh *head)
{
  struct yogesh *f = head;
  while (f != NULL)
  {
    printf("%d", f->value);
    f = f->next;
  }
}

int main()
{
  struct yogesh *first = (struct yogesh *)malloc(sizeof(struct yogesh));
  struct yogesh *second = (struct yogesh *)malloc(sizeof(struct yogesh));
  struct yogesh *third = (struct yogesh *)malloc(sizeof(struct yogesh));
  struct yogesh *fourth = (struct yogesh *)malloc(sizeof(struct yogesh));

  first->value = 1;
  first->next = second;
  first->previous = NULL;

  second->value = 2;
  second->next = third;
  second->previous = first;

  third->value = 3;
  third->next = fourth;
  third->previous = second;

  fourth->value = 4;
  fourth->next = NULL;
  fourth->previous = third;

  printf("Before Insertion in doubly linked list is : \n");
  traverse_list_forward(first);
  insertLast(fourth, 5);
  printf("\nAfter Insertion in doubly linked list is : \n");
  traverse_list_forward(first);
  return 0;
}