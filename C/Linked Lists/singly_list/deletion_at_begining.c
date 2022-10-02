#include <stdio.h>
#include <stdlib.h>
struct yogesh
{
    int value;
    struct yogesh *next;
};

struct yogesh *deleteBeg(struct yogesh *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct yogesh *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void insert(struct yogesh **head_ref, int new_data)
{
    struct yogesh *new_node = (struct yogesh *)malloc(sizeof(struct yogesh));
    new_node->value = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
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

    insert(&first, 12);
    insert(&first, 29);
    insert(&first, 11);
    insert(&first, 23);
    insert(&first, 8);

    printf("Array before deletion : \n");
    traverse_array(first);
    deleteBeg(first);
    printf("Array after deletion : \n");
    traverse_array(first);
    return 0;
}