#include <iostream>
using namespace std;
struct yogesh
{
    int value;
    yogesh *next;
};

struct yogesh *top;

void push(int data)
{
    struct yogesh *a = (struct yogesh *)malloc(sizeof(struct yogesh));
    if (!a)
    {
        cout << "Stack Overflow !!";
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
        cout << "\nStack Underflow";
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

void pop()
{
    struct yogesh *ptr;
    if (top == NULL)
    {
        printf("\nStack Underflow !!!");
    }
    else
    {
        ptr = top;
        top = top->next;
        ptr->next = NULL;
        free(ptr);
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(500);
    push(404);
    cout << "Elements of the stack before pop() are : "
         << " \n";
    traverse_stack();
    pop();
    pop();
    cout << "\nElements of the stack after pop() are : "
         << " \n";
    traverse_stack();
    return 0;
}