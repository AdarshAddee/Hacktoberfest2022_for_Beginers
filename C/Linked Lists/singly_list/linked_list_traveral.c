#include <stdio.h>
#include <stdlib.h>
struct yogesh
{
    int data;
    struct yogesh *next;
};

void simple_traversal(struct yogesh *head)
{
    struct yogesh *latest = head;
    while (latest != NULL)
    {
        printf("The data is : %d \n", latest->data);
        latest = latest->next;
    }
}

int main()
{
    struct yogesh *first;
    struct yogesh *second;
    struct yogesh *third;

    first = (struct yogesh *)malloc(sizeof(struct yogesh));
    second = (struct yogesh *)malloc(sizeof(struct yogesh));
    third = (struct yogesh *)malloc(sizeof(struct yogesh));

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    simple_traversal(first);

    return 0;
    return 0;
}
