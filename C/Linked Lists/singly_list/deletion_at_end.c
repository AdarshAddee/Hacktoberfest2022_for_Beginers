#include <stdio.h>
#include <stdlib.h>

struct yogesh
{
    int value;
    struct yogesh *next;
};

struct yogesh *insertEnd(struct yogesh *head, int data)
{
    struct yogesh *temp = (struct yogesh *)malloc(sizeof(struct yogesh));
    temp->value = data;
    if (head == NULL)
    {
        return temp;
    }
    struct yogesh *latest = head;
    while (latest->next != NULL)
    {
        latest = latest->next;
    }
    latest->next = temp;
    return head;
}

struct yogesh *deleteEnd(struct yogesh *head)
{
    struct yogesh *a = head;
    struct yogesh *b = head->next;

    while (b->next != NULL)
    {
        a = a->next;
        b = b->next;
    }
    a->next = NULL;
    free(b);
    return a;
}

void traverse_array(struct yogesh *ptr)
{
    while (ptr != NULL)
    {
        printf("The element in list is : %d \n", ptr->value);
        ptr = ptr->next;
    }
}

int main()
{
    struct yogesh *first = NULL;
    first = insertEnd(first, 1);
    first = insertEnd(first, 2);
    first = insertEnd(first, 3);
    first = insertEnd(first, 4);

    printf("List before deletion : \n");
    traverse_array(first);
    deleteEnd(first);
    printf("List after deletion : \n");
    traverse_array(first);
    return 0;
}