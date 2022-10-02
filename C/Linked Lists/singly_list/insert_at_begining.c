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

    traverse_array(first);
    return 0;
}