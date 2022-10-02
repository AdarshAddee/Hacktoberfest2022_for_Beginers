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
    first = insertEnd(first, 4);
    first = insertEnd(first, 3);
    first = insertEnd(first, 2);
    first = insertEnd(first, 1);

    traverse_array(first);
    return 0;
}