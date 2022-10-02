#include <iostream>
using namespace std;
struct yogesh
{
    int value;
    yogesh *next;
    yogesh *previous;
};

void traverse_list(yogesh *head)
{
    yogesh *f = head;
    while (f != NULL)
    {
        cout << f->value;
        f = f->next;
    }
}

void insertEnd(yogesh *last, int data)
{
    yogesh *a = new yogesh();
    a->value = data;

    a->next = NULL;
    a->previous = last;
    last->next = a;
    last = a;
}

int main()
{
    yogesh *first = new yogesh();
    yogesh *second = new yogesh();
    yogesh *third = new yogesh();
    yogesh *fourth = new yogesh();

    first->value = 1;
    first->next = second;
    first->previous = NULL;

    second->value = 2;
    second->next = third;
    second->previous = first;

    third->value = 3;
    third->next = fourth;
    third->previous = second;

    fourth->value = 4;
    fourth->next = NULL;
    fourth->previous = third;

    cout << "Before Insertion in Doubly  linked list is : \n";
    traverse_list(first);
    insertEnd(fourth, 5);
    cout << "\nAfter Insertion in Doubly  linked list is : \n";
    traverse_list(first);
    return 0;
}