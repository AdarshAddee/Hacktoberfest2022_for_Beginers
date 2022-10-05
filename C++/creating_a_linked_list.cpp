//GitHub username : Himangshu-101
//Aim : Creating a linked list
//Date : 05/10/2022


#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

//creating a linked list
node* create_LL(struct node *head)
{
    int num;
    printf("Enter the no of nodes:\t");
    scanf("%d", &num);
    while (num--)
    {
        //Initialising a new node
        node *new_node = new node;
        int dE_ARR;
        printf("Enter the data:");
        scanf("%d", &dE_ARR);

        //assigning data and next to the new node
        new_node->data = dE_ARR;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            struct node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }
    }

    return head;
}

//function to print the linked list
void display(node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

//driver code
int main()
{
    node *head = NULL;
    head = create_LL(head);
    display(head);

    return 0;
}