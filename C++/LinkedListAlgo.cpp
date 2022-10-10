#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data)
    {
        this -> data =data;
        this -> next=NULL;
    }
};


//code to insert at head
void insertathead(node* &head, int val)
{
    node* temp=new node(val);
    temp->next=head;
    head=temp;
}

//to display 
void display(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//reverse the linked list by recursion
node* reverseRecursive(node* &head){

    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    node* newhead = reverseRecursive(head -> next);
    head ->next-> next = head;
    head -> next = NULL; 

    return newhead;
}

//code to inset at head
void inserattail(node* &tail,int val)
{
    node* temp=new node(val);
    tail->next=temp;
    tail=tail->next;
    tail=temp;
}

//code to insert at position
void insertatpostition(node* &head,node* &tail,int pos,int val)
{
    if(pos==1)
    {
        insertathead(head,val);
        return;
    }
    
    node* temp=head;
    int cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    node* nodetoinsert=new node(val);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;

    if(temp->next==NULL)
    {
        inserattail(tail,val);
        return;
    }
}

//code to delete the node
void deletenode(node* &head,node* &tail,int pos)
{
    if(pos==1)
    {
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node* curr=head;
        node* prev=NULL;
        int cnrt=1;
        while(cnrt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnrt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}

//code to reverse the linked ist
void reverse(node* &head)
{
    node* prev=NULL;
    node* curr=head;
    node* nextptr;
    while(curr!=NULL)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    head=prev;
}

//code to reverse k-nodes
node* reversek(node* &head,int k)
{
    node*prev=NULL;
    node*curr=head;
    node* nextptr;
    int count=0;
    while(curr!=NULL && count<k)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        count++;
    }
    if(nextptr!=NULL)
    {
        head->next=reversek(nextptr, k);
    }
    head=prev;
    return head;
}

//code to create a cycle
void createcycle(node* &head, int pos)
{
    node* temp=head;
    node* startnode;
    int count=1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode->next;
}

//code to detect cycle
bool detectcycle(node* &head)
{
    node* rabbit=head;
    node* turtle=head;
    while(rabbit!=NULL && rabbit->next!=NULL)
    {
        turtle=turtle->next;
        rabbit=rabbit->next->next;
        if(turtle==rabbit)
        {
            return true;
        }
    }
    return false;
}

//code to delete the cycle
void deletecycle(node* &head)
{
    node* turtle=head;
    node* rabbit=head;
    while(rabbit!=NULL && rabbit->next!=NULL)
    {
        turtle=turtle->next;
        rabbit=rabbit->next->next;
        if(turtle==rabbit)
        {
            rabbit=head;
            while(rabbit!=NULL)
            {
                turtle=turtle->next;
                rabbit=rabbit->next;
                if(turtle->next==rabbit)
                {
                    turtle=NULL;
                }
            }
        }
    }
}

//code to get the length
int length(node* &head)
{
    int count=1;
    node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count-1;
}

//code to search the node
void search(node* &head,int ele)
{
    int a=0;
    node* temp=head;
    while(temp!=NULL)
    {
        if(ele==temp->data)
        {
            a=1;;
            break;
        }
        else
        {
            temp=temp->next;
        }
    }
    cout<<"Search function:- ";
    if(a!=0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    cout<<endl;
}

//code to get the index
void getindex(node* &head,int pos)
{
    node* temp=head;
    int count=0,index=0;
    while(temp!=NULL)
    {
        if(temp->data==pos)
        {
            index=count;
            break;
        }
        temp=temp->next;
        count++;
    }
    cout<<"The index of the value is:- "<<index<<endl;
}

//code to get the node
void getnode(node*&head,int value)
{
    int count=0;
    node* temp=head;
    while(temp!=NULL)
    {
        if(count==value)
        {
            cout<<temp->data<<endl;
            break;
        }
        temp=temp->next;
        count++;
    }
}

//code to detect the frequency
void frequency(node* &head,int val)
{
    int count=0;
    node* temp=head;
    while(temp!=NULL)
    {
        if(val==temp->data)
        {
            count++;
        }
        temp=temp->next;
    }
    cout<<"The frequency is:- "<<count;
}


int main()
{
    node* new1=new node(1);
    node* tail=new1;
    node* head=new1;
    //display(head);

    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);
    display(head);

   insertatpostition(head,tail,1,16);
    insertatpostition(head,tail,6,123);
    display(head);

    deletenode(head,tail,1);
    deletenode(head,tail,5);
    deletenode(head,tail,3);
    cout<<"deleted node:- "<<display(head);

    reverse(head);
    display(head);

    reversek(head,2);
    display(head);
    reverse(head);
    display(head);
   createcycle(head,3);

    //for boolian function we will use cout.
    cout<<detectcycle(head)<<endl;
    deletecycle(head);
    display(head);

    cout<<"The length of the linked list is:- ";
    length(head);
    search(head,2);
    getindex(head,2);
    getnode(head,1);*/
    
    //middle(head);------------------>>>>

   frequency(head,2);
    circularathead(head,8);
    display(head);

    node* ne=reverseRecursive(head);
    display(ne);

}
