#include<bits/stdc++.h>
using namespace std;
class linkedlist;
class node
{
    int data;
    node* next;
    public:
    node();
    node(int val);
    friend class linkedlist;
};
class linkedlist
{
    node* head;
    public:
    linkedlist();
    void insertnode(int val);
    void insertatfront(int val);
    void insertaftergiven(int val,int i);
    void insertatmid(int val);
    void deleteatbegin();
    void deletefromend();
    void deleteatmid();
    int length();
    bool search(int val);
    int getNth(int i);
    void getNthend(int i);
    int countfreq(int n);
    bool loop();
    void traverse();

};
node::node()
{
    data=0;
    next=NULL;
}
node::node(int val)
{
    data=val;
    next=NULL;
}
linkedlist::linkedlist()
{
    head=NULL;
}
void linkedlist::insertnode(int val)
{
    node* newnode=new node(val);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
        return;
    }
}
void linkedlist::insertatfront(int val)
{
    node* newnode=new node(val);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void linkedlist::insertaftergiven(int val,int i)
{
    node* temp=head;
    node* newnode=new node(val);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data==i)
            {
                newnode->next=temp->next;
                temp->next=newnode;
                return;
            }
            temp=temp->next;
        }
       
    }
}
void linkedlist::insertatmid(int val)
{
    int count=0;
    node* temp=head;
    node* newnode=new node(val);
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    int i=((count%2==0)?(count/2):(count+1)/2);
    temp=head;
    while(i-->1)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;

}
void linkedlist::deleteatbegin()
{
    if(head==NULL)
    {
        return;
    }
    node* temp=head;
    head=temp->next;
    delete temp;
}
void linkedlist::deletefromend()
{
    if(head==NULL)
    {
        return;
    }
    node* temp=head;
    node* prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    delete temp;
    
}
void linkedlist::deleteatmid()
{
    
}
int linkedlist::length()
{
    int count=0;
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        node* temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
    }
    return count;
}
bool linkedlist::search(int val)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}
int linkedlist::getNth(int i)
{
    node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        if(count==i)
        {
            return temp->data;
        }
        count++;
        temp=temp->next;
    }
}
void linkedlist::getNthend(int i)
{
    node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    if(count<0)
    {
        return;
    }
    temp=head;
    for(int j=0;j<count-i-1;j++)
    {
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
    return;
}
int linkedlist::countfreq(int n)
{
    int count=0;
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            count++;
        }
        temp=temp->next;
    }
    return count;
}
bool linkedlist::loop()
{
    node* slow=head;
    node* fast=head;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}
void linkedlist::traverse()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}
int main()
{
    linkedlist l;
    l.insertnode(6);
    l.insertnode(4);
    l.insertnode(9);
    l.insertnode(56);
    l.insertnode(9);
    l.insertnode(32);
    l.insertnode(89);
    l.insertnode(4);
    l.traverse();
    l.insertatfront(34);
    l.traverse();
    l.insertaftergiven(32,9);
    l.traverse();
    l.insertatmid(66);
    l.traverse();
    l.deleteatbegin();
    l.traverse();
    l.deletefromend();
    l.traverse();
    cout<<"The length of the linkedlist is:"<<l.length()<<endl;
    cout<<l.search(9)<<endl;
    cout<<l.getNth(2)<<endl;
    l.getNthend(0);
    cout<<"The frequency of the given number is:"<<l.countfreq(9)<<endl;
    cout<<l.loop()<<endl;
    return 0;
}