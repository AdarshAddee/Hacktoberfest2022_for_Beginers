//  Kashish Ahuja
//  Program for operations on circular doubly linked list

#include<iostream>
using namespace std;
#include<stdlib.h>

struct CircularDoublyLinkedList
{
    int data;
    struct CircularDoublyLinkedList *prev, *next;
};

typedef struct CircularDoublyLinkedList node;
node *start=NULL;
node *last=NULL;

class CDLL
{
    private:
        int count = 0;
    
    public:
        void insertAtBegin()
        {
            node *p;
            p=new node;
            cout<<"\nEnter element to be inserted: ";
            cin>>p->data;
            if(start==NULL)
            {
                start=last=p;
                p->prev=p->next=p;
            }
            else
            {
                p->next=start;
                start->prev=p;
                start=p;
                start->prev=last;
                last->next=start;
            }
            cout<<p->data<<" is inserted at the beginning";
            count++;
        }

        void insertAtPosition()
        {
            int pos; 
            cout<<"\nEnter position to insert element: ";
            cin>>pos;
            if(pos>0 && pos<=count+1)
            {
                node *p;
                p=new node;
                cout<<"Enter element to be inserted: ";
                cin>>p->data;
                if(pos==1)
                {
                    if(start==NULL)
                    {
                        start=last=p;
                        p->prev=p->next=p;
                    }
                    else
                    {
                        p->next=start;
                        start->prev=p;
                        start=p;
                        start->prev=last;
                        last->next=start;
                    }
                }
                else if(pos==count+1)
                {
                    last->next=p;
                    p->prev=last;
                    last=p;
                    last->next=start;
                    start->prev=last;
                }
                else
                {
                    node *temp;
                    temp=start;
                    int i=1;
                    while(i<pos-1)
                    {
                        temp=temp->next;
                        i++;
                    }
                    p->next=temp->next;
                    p->prev=temp;
                    temp->next->prev=p;
                    temp->next=p;
                }
                cout<<p->data<<" is inserted at position "<<pos;
                count++;
            }
            else
                cout<<"\nPosition "<<pos<<" does not exist in list";
        }

        void insertAtEnd()
        {
            node *p;
            p=new node;
            cout<<"\nEnter element to be inserted: ";
            cin>>p->data;
            if(start==NULL)
            {
                start=last=p;
                p->prev=p->next=p;
            }
            else
            {
                last->next=p;
                p->prev=last;
                last=p;
                last->next=start;
                start->prev=last;
            }
            cout<<p->data<<" is inserted at the end";
            count++;
        }

        void displayForward()
        {
            node *temp;
            temp=start;
            cout<<"\nList: ";
            if(start!=NULL)
            {
                while(temp->next != start)  
                {  
                    cout<<temp->data<<" ";  
                    temp = temp->next;  
                }  
                cout<<temp->data;
            }
        }

        void displayBackward()
        {
            node *temp;
            temp=last;
            cout<<"\nList: ";
            if(last!=NULL)
            {
                while(temp->prev!=last)
                {
                    cout<<temp->data<<" ";
                    temp=temp->prev;
                }
                cout<<temp->data<<" ";
            }
        }

        void deleteFromBegin()
        {
            if(start==NULL)
                cout<<"\nList underflow";
            else
            {
                node *temp;
                temp=start;
                if(start==last)
                    start=last=NULL;
                else
                {
                    start=start->next;
                    start->prev=last;
                    last->next=start;
                }
                cout<<"\n"<<temp->data<<" is deleted from beginning";
                delete(temp);
                count--;
            }
        }

        void deleteFromPosition()
        {
            if(start==NULL)
                cout<<"\nList underflow";
            else
            {
                int pos;
                cout<<"\nEnter position to delete element: ";
                cin>>pos;
                if(pos>0 && pos<=count)
                {   
                    node *temp;
                    if(pos==1)
                    {
                        temp=start;
                        if(start==last)
                            start=last=NULL;
                        else
                        {
                            start=start->next;
                            start->prev=last;
                            last->next=start;
                        }
                    }
                    else if(pos==count)
                    {
                        temp=last;
                        last=last->prev;
                        last->next=start;
                        start->prev=last;
                    }
                    else
                    {
                        node *p, *q;
                        temp=start;
                        int i=1;
                        while(i<pos)
                        {
                            p=temp;
                            temp=temp->next;
                            i++;
                        }
                        p->next=temp->next;
                        q=temp->next;
                        q->prev=p;
                        temp->next=temp->prev=NULL;            
                    }
                    cout<<temp->data<<" is deleted from position "<< pos;
                    delete(temp);
                    count--;
                }
                else
                    cout<<"Position "<<pos<<" does not exist in list";
            }
        }

        void deleteFromEnd()
        {
            if(start==NULL)
                cout<<"\nList underflow";
            else
            {
                node *temp;
                if(start==last)
                {
                    temp=start;
                    start=last=NULL;
                }
                else
                {
                    temp=last;
                    last=last->prev;
                    last->next=start;
                    start->prev=last;
                }
                cout<<"\n"<<temp->data<<" is deleted from end";
                delete(temp);
                count--;
            }
        }   
};

int main()
{
    CDLL cdll;
    int choice;
    do
    {
        cout<<"\n\n1) Insert an element at the beginning\n2) Insert an element at a position\n3) Insert an element at the end\n4) Display (Forward)\n5) Display (Backward)\n6) Delete an element from the beginning\n7) Delete an element from a position\n8) Delete an element from the end\n9) Exit";
        cout<<"\nEnter you choice: ";
        cin>>choice;

        switch (choice)
        {
            case 1: cdll.insertAtBegin();
                    break;

            case 2: cdll.insertAtPosition();
                    break;

            case 3: cdll.insertAtEnd();
                    break;

            case 4: cdll.displayForward();
                    break;

            case 5: cdll.displayBackward();
                    break;

            case 6: cdll.deleteFromBegin();
                    break;

            case 7: cdll.deleteFromPosition();
                    break;

            case 8: cdll.deleteFromEnd();
                    break;
                
            case 9: exit(0);

            default: cout<<"\nInvalid choice";
        }

    } while (choice!=9);
    return 0;
}