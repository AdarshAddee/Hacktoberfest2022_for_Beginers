#include <iostream>
using namespace std;

#define size 4

int arr[size];
int rear = -1;
int front = -1;

void enqueue()
{
    int add_item;
    if (rear == size - 1)
    {
        cout << "Queue Overflow \n";
    }
    else
    {
        if (front == -1)
            front = 0;
        cout << "Inset the element in queue : ";
        scanf("%d", &add_item);
        rear = rear + 1;
        arr[rear] = add_item;
    }
}

void traversal_queue()
{
    int i;
    if (front == -1)
    {
        cout << "Queue is empty \n";
    }
    else
    {
        cout << "Queue is : \n";
        for (i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    for (int i = 0; i < size; i++)
    {
        enqueue();
    }
    traversal_queue();
}
