#include <iostream>
using namespace std;

struct yogesh
{
    int data;
    yogesh *next;
};

void simple_traversal(yogesh *head)
{
    yogesh *latest = head;
    while (latest != NULL)
    {
        cout << "The data is : " << latest->data << "\n";
        latest = latest->next;
    }
}

int main()
{
    yogesh *first;
    yogesh *second;
    yogesh *third;

    first = new yogesh();
    second = new yogesh();
    third = new yogesh();

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    simple_traversal(first);

    return 0;
}