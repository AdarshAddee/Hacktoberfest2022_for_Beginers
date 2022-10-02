#include <iostream>
using namespace std;

struct yogesh
{
    int data;
    yogesh *next;
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

int Length(yogesh *head)
{
    yogesh *current = head;
    int count = 0;

    if (head == NULL)
    {
        return 0;
    }
    else
    {
        do
        {
            current = current->next;
            count++;
        } while (current != head);
    }
    return count;
}

void deleteBeg(yogesh **head)
{
    struct yogesh *previous = *head, *next = *head;

    if (*head == NULL)
    {
        cout << "\nList is empty\n";
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

void deleteAtChoice(yogesh **head, int index)
{

    int len = Length(*head);
    int count = 1;
    yogesh *previous = *head, *next = *head;

    if (*head == NULL)
    {
        cout << "\nDelete Last List is empty\n";
        return;
    }

    if (index >= len || index < 0)
    {
        cout << "\nIndex is not Found\n";
        return;
    }

    if (index == 0)
    {
        deleteBeg(head);
        return;
    }

    while (len > 0)
    {

        if (index == count)
        {
            previous->next = next->next;
            free(next);
            return;
        }
        previous = previous->next;
        next = previous->next;
        len--;
        count++;
    }
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
    cout << "\nAfter Deleting node at index 4: ";
    deleteAtChoice(&head, 3);
    traverse_list(head);

    return 0;
}
