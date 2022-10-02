#include <stdio.h>
#include <stdlib.h>

struct yogesh
{
    int value;
    struct yogesh *next;
};

struct yogesh *top;

void push(int data)
{
    struct yogesh *a = (struct yogesh *)malloc(sizeof(struct yogesh));
    if (!a)
    {
        printf("Stack Overflow !!");
    }
    else
    {
        a->value = data;
        a->next = top;
        top = a;
    }
}

void traverse_stack()
{
    struct yogesh *ptr;
    if (top == NULL)
    {
        printf("\nStack Underflow");
    }
    else
    {
        ptr = top;
        while (ptr != NULL)
        {
            printf("%d ", ptr->value);
            ptr = ptr->next;
        }
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    printf("Elements of the stack are : \n");
    traverse_stack();
}