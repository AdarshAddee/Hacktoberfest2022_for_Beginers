#include <iostream>
using namespace std;
struct yogesh
{
    int value;
    yogesh *next;
};

void linkedListTraversal(yogesh *head)
{
    yogesh *ptr = head;
    do
    {
        cout << ptr->value << "\n";
        ptr = ptr->next;
    } while (ptr != head);
}

yogesh *insertBeg(yogesh *head, int data)
{
    yogesh *ptr = new yogesh();
    ptr->value = data;

    yogesh *p = head->next;
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

    yogesh *head = new yogesh();
    yogesh *second = new yogesh();
    yogesh *third = new yogesh();
    yogesh *fourth = new yogesh();

    head->value = 1;
    head->next = second;

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = fourth;

    fourth->value = 4;
    fourth->next = head;

    cout << "Circular Linked list before insertion\n";
    linkedListTraversal(head);
    head = insertBeg(head, 54);
    cout << "Circular Linked list after insertion\n";
    linkedListTraversal(head);
    return 0;
}