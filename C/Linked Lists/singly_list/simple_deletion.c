#include <stdio.h>
#include <stdlib.h>
struct yogesh
{
  int value;
  struct yogesh *next;
};

void traverse_array(struct yogesh *ptr)
{
  while (ptr != NULL)
  {
    printf("%d", ptr->value);
    ptr = ptr->next;
  }
}

int main()
{
  struct yogesh *first = (struct yogesh *)malloc(sizeof(struct yogesh));
  struct yogesh *second = (struct yogesh *)malloc(sizeof(struct yogesh));
  struct yogesh *third = (struct yogesh *)malloc(sizeof(struct yogesh));

  first->value = 1;
  first->next = second;

  second->value = 2;
  second->next = third;

  third->value = 3;
  third->next = NULL;

  printf("Array before Deletion : \n");
  traverse_array(first);
  first->next = third;
  free(second);
  printf("\nArray After Deletion : \n");
  traverse_array(first);
}