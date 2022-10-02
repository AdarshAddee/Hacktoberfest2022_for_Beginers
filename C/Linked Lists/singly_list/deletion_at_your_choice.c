#include <stdio.h>
#include <stdlib.h>

struct yogesh
{
    int value;
    struct yogesh *next;
};

struct yogesh *insertBeg(struct yogesh *head, int data)
{
    struct yogesh *temp = (struct yogesh *)malloc(sizeof(struct yogesh));
    temp->value = data;
    temp->next = head;
    return temp;
}

struct yogesh *deleteAtChoice(struct yogesh *head, int index)
{
    struct yogesh *a = head;
    struct yogesh *b = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        a = a->next;
        b = b->next;
    }
    a->next = b->next;
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
    first = insertBeg(first, 4);
    first = insertBeg(first, 3);
    first = insertBeg(first, 2);
    first = insertBeg(first, 1);

    printf("List before deletion : \n");
    traverse_array(first);
    deleteAtChoice(first, 2);
    printf("List after deletion : \n");
    traverse_array(first);
    return 0;
}