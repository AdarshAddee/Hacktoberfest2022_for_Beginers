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
void deleteEnd(yogesh *last)
{
    yogesh *a = last;
    last->previous->next = NULL;
    delete last;
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

    cout << "Before Deletion in doubly linked list is : \n";
    traverse_list_forward(first);
    cout << "\nAfter Deletion in doubly linked list is : \n";
    deleteEnd(fourth);
    traverse_list_forward(first);
    return 0;
}