#include <stdio.h>
#include <stdlib.h>

struct yogesh
{
    int value;
    struct yogesh *previous;
    struct yogesh *next;
};

void traverse_list_forward(struct yogesh *head)
{
    struct yogesh *f = head;
    while (f != NULL)
    {
        printf("%d", f->value);
        f = f->next;
    }
}

void traverse_list_backward(struct yogesh *head, struct yogesh *last)
{
    struct yogesh *b = last;
    while (b != head->previous)
    {
        printf("%d", b->value);
        b = b->previous;
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

    printf("Forward Traversal of doubly linked list is : \n");
    traverse_list_forward(first);
    printf("\nBackward Traversal of doubly linked list is : \n");
    traverse_list_backward(first, fourth);
    return 0;
}