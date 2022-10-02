#include <stdio.h>
#include <stdlib.h>

struct yogesh
{
    int value;
    struct yogesh *next;
};

void travere_linked_list(struct yogesh *head)
{
    struct yogesh *a = (struct yogesh *)malloc(sizeof(struct yogesh));
    a = head;
    do
    {
        printf("%d\n", a->value);
        a = a->next;
    } while (a != head);
}

struct yogesh *insertAtEnd(struct yogesh *head, int data)
{
    struct yogesh *newnode = (struct yogesh *)malloc(sizeof(struct yogesh));
    newnode->value = data;

    struct yogesh *ptr = head->next;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->next = head;
    head = ptr;
    return head;
}

int main()
{
    struct yogesh *first = (struct yogesh *)malloc(sizeof(struct yogesh));
    struct yogesh *second = (struct yogesh *)malloc(sizeof(struct yogesh));
    struct yogesh *third = (struct yogesh *)malloc(sizeof(struct yogesh));
    struct yogesh *fourth = (struct yogesh *)malloc(sizeof(struct yogesh));

    first->value = 1;
    first->next = second;

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = fourth;

    fourth->value = 4;
    fourth->next = first;

    printf("Linked List before insertion : \n");
    travere_linked_list(first);
    insertAtEnd(first, 45);
    printf("Linked List After insertion : \n");
    travere_linked_list(first);

    return 0;
}