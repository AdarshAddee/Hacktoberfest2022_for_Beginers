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

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    cout << "Elements of the stack are : "
         << " \n";
    traverse_stack();
    return 0;
}