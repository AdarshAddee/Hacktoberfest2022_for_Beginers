#include <stdio.h>
#include <stdlib.h>

struct yogesh
{
    int value;
    struct yogesh *next;
};

void linkedListTraversal(struct yogesh *head)
{
    struct yogesh *ptr = head;
    do
    {
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    } while (ptr != head);
}

struct yogesh *insertBeg(struct yogesh *head, int data)
{
    struct yogesh *ptr = (struct yogesh *)malloc(sizeof(struct yogesh));
    ptr->value = data;

    struct yogesh *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{

    struct yogesh *head;
    struct yogesh *second;
    struct yogesh *third;
    struct yogesh *fourth;

    head = (struct yogesh *)malloc(sizeof(struct yogesh));
    second = (struct yogesh *)malloc(sizeof(struct yogesh));
    third = (struct yogesh *)malloc(sizeof(struct yogesh));
    fourth = (struct yogesh *)malloc(sizeof(struct yogesh));

    head->value = 1;
    head->next = second;

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = fourth;

    fourth->value = 4;
    fourth->next = head;

    printf("Circular Linked list before insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 54);
    printf("Circular Linked list after insertion\n");
    linkedListTraversal(head);
    return 0;
}