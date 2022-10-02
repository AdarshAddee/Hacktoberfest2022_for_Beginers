#include <stdio.h>
#include <stdlib.h>

struct yogesh
{
    int data;
    struct yogesh *next;
};

void insertBeg(struct yogesh **head, int data)
{
    struct yogesh *current = *head;
    struct yogesh *newNode = (struct yogesh *)malloc(sizeof(struct yogesh));
    newNode->data = data;
    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    else
    {

        while (current->next != *head)
        {
            current = current->next;
        }
        newNode->next = *head;
        current->next = newNode;
    }
}

void traverse_list(struct yogesh *head)
{
    struct yogesh *current = head;

    if (head == NULL)
    {
        printf("\nDisplay List is empty\n");
        return;
    }
    else
    {
        do
        {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }
}
void deleteBeg(struct yogesh **head)
{
    struct yogesh *previous = *head, *next = *head;

    if (*head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    if (previous->next == previous)
    {
        *head = NULL;
        return;
    }

    while (previous->next != *head)
    {

        previous = previous->next;
        next = previous->next;
    }
    previous->next = next->next;
    *head = previous->next;
    free(next);

    return;
}

int main()
{
    struct yogesh *head = NULL;

    insertBeg(&head, 1);
    insertBeg(&head, 2);
    insertBeg(&head, 3);
    insertBeg(&head, 4);
    insertBeg(&head, 5);

    printf("Circular Linked list before deletion : \n");
    traverse_list(head);
    printf("Circular Linked list After deletion : \n");
    deleteBeg(&head);
    traverse_list(head);

    return 0;
}
