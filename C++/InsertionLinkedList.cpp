#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
struct node* head = NULL;
void insert_beg(int new_data){
    
    struct node* new_node = new node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}
void display(){
    struct node* ptr;
    ptr = head;
    if (ptr==NULL){
        cout<<"empty.";
    }
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}
int main(){
    insert_beg(1);
    insert_beg(2);
    cout<<"the list is : ";
    display();
    return 0;
}
