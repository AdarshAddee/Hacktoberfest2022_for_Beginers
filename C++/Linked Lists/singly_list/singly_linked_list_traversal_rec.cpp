#include <iostream>
using namespace std;

struct yogesh
{
    int data;
    yogesh *next;
};

void recursive_traversal(yogesh *head)
{
    yogesh *latest = head;
    if (latest == NULL)
    {
        return;
    }
    cout << "The data is : " << latest->data << "\n";
    recursive_traversal(latest->next);
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

    recursive_traversal(first);

    return 0;
}

// Iterative approach has O(1) time complexity while recursive approch has O(n) time complexity
