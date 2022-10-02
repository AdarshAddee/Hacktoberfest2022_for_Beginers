#include <stdio.h>
#include <stdlib.h>

#define size 4

int arr[size];
int rear = -1;
int front = -1;

void enqueue()
{
    int add_item;
    if (rear == size - 1)
    {
        printf("Queue Overflow \n");
    }
    else
    {
        if (front == -1)
            front = 0;
        printf("Inset the element in queue : ");
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
        printf("Queue is empty \n");
    }
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
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
