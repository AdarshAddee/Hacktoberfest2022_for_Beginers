#include <stdio.h>
#include <stdlib.h>

struct listelem
{
    int value;
    struct listelem *next;
};

int main()
{
    struct listelem *first;
    struct listelem *second;
    struct listelem *third;

    first = (struct listelem *)malloc(sizeof(struct listelem));
    second = (struct listelem *)malloc(sizeof(struct listelem));
    third = (struct listelem *)malloc(sizeof(struct listelem));

    first->value = 1;
    first->next = second;

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = NULL;

    traverse_array(first);
    return 0;
}

void traverse_array(struct listelem *ptr)
{
    while (ptr != NULL)
    {
        printf("The element in list is : %d \n", ptr->value);
        ptr = ptr->next;
    }
}