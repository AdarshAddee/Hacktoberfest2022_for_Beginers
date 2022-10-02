#include <iostream>
using namespace std;

struct yogesh
{
    int data;
    struct yogesh *next;
};

void insertBeg(yogesh **head, int data)
{
    yogesh *current = *head;
    yogesh *newNode = new yogesh();
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

void traverse_list(yogesh *head)
{
    yogesh *current = head;

    if (head == NULL)
    {
        cout << "\nDisplay List is empty\n";
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

void deleteEnd(struct yogesh **head)
{
    struct yogesh *current = *head, *temp = *head, *previous;
    if (*head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    if (current->next == current)
    {
        *head = NULL;
        return;
    }
    while (current->next != *head)
    {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    *head = previous->next;
    free(current);

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

    cout << "Circular Linked list before deletion\n";
    traverse_list(head);
    cout << "\nCircular Linked List After deletion \n";
    deleteEnd(&head);
    traverse_list(head);

    return 0;
}
