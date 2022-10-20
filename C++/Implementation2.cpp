#include <bits/stdc++.h>
#include "Linkedlist.h"
using namespace std;
LinkedList *implementation()
{
    LinkedList *head = NULL;
    int value;
    cout << "Enter the value" << endl;
    cin >> value;
    while (value != -1)
    {
        LinkedList *newNode = new LinkedList(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            LinkedList *temp = head;
            while(temp->next!=NULL){
                temp=temp->next;}
            temp->next = newNode;
            
        }
        cout << "Enter the other data for the linked list" << endl;
        cin >> value;
    }
    return head;
}

int main()
{
    LinkedList *head = implementation();
    while (head != NULL)
    {
        cout << head->value <<" --> " ;
        head = head->next;
    }
    cout<<"NULL";
}
