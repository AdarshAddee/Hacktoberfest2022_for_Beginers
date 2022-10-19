// username - heyabhinav
// Aim - To sort 0, 1 and 2 in a Linked List without changing the in the nodes instead change the links between node.
// date - 19-October-2022

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        // node(){};
        node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void print(node* head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next; 
    }
    cout << "NULL" << endl;
    
    return;
}

void insertAtTail(node* &tail, node* curr){
    // node* temp = new node(data);
    tail->next = curr;
    tail = curr;
}

node* sort012(node* &head){
    if(head==NULL){
        return NULL;
    }

    node* zeroHead = new node(-1);
    node* zeroTail = zeroHead;
    node* oneHead = new node(-1);
    node* oneTail = oneHead;
    node* secondHead = new node(-1);
    node* secondTail = secondHead;

    node* curr = head;
    while(curr != NULL){
        if(curr->data == 0){
            insertAtTail(zeroTail, curr);
        }
        else if(curr->data == 1){
            insertAtTail(oneTail, curr);
        }
        else{
            insertAtTail(secondTail, curr);
        }

        curr = curr->next;

    }

    if(oneHead->next == NULL){
        zeroTail->next = secondHead->next;
        
    }
    else{
        zeroTail->next = oneHead->next;
    }

    // oneTail->next = secondHead->next;
    secondTail->next = NULL;

    node* t = zeroHead->next;

    return t;
}

int main(){
    node* head = new node(0);
    node* second = new node(1);
    node* third = new node(0);
    node* fourth = new node(2);
    node* fifth = new node(1);
    node* six = new node(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = six;
    // six->next = second;

    head = sort012(head);

    // print(head)

    print(head);
    return 0;
}