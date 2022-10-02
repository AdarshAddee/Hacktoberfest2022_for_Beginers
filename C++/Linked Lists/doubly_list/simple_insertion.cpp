#include <iostream>
using namespace std;
struct yogesh
{
    int value;
    yogesh *next;
    yogesh *previous;
};

void traverse_list_forward(yogesh *head)
{
    yogesh *f = head;
    while (f != NULL)
    {
        cout << f->value;
        f = f->next;
    }
}

void traverse_list_backward(yogesh *head, yogesh *last)
{
    yogesh *b = last;
    while (b != head->previous)
    {
        cout << b->value;
        b = b->previous;
    }
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

    cout << "Forward Traversal of doubly linked list is : \n";
    traverse_list_forward(first);
    cout << "Backward Traversal of doubly linked list is : \n";
    traverse_list_backward(first, fourth);
    return 0;
}