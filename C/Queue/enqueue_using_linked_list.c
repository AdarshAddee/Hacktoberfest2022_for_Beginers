#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int value;
    struct queue *next;
} * front, *rear, *temp, *fr;

void enqueue(int data)
{
    if (rear == NULL)
    {
        rear = (struct queue *)malloc(sizeof(struct queue));
        rear->next = NULL;
        rear->value = data;
        front = rear;
    }
    else
    {
        temp = (struct queue *)malloc(sizeof(struct queue));
        rear->next = temp;
        temp->value = data;
        temp->next = NULL;

        rear = temp;
    }
}

void traverse_queue()
{
    fr = front;

    if ((fr == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (fr != rear)
    {
        printf("%d ", fr->value);
        fr = fr->next;
    }
    if (fr == rear)
        printf("%d", fr->value);
}

int main()
{
    int size, elem;
    printf("Enter the size of the Queue : \n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the Element :\n");
        scanf("%d", &elem);
        enqueue(elem);
    }
    printf("Queue is : \n");
    traverse_queue();
}