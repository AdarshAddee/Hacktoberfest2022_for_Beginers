#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this -> data= data;
        this -> next = NULL;
    }
};

void InsertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}



void print(Node *head){
    if(head==NULL) 
         cout<<"null";
    while(head!=NULL){
        cout<<head-> data<<" ";
        head=head -> next;
    }
}


 Node* removeNthFromEnd(Node* head, int n) {
       Node *temp = head, *s=head, *pr=NULL;
       int a=1;
       while(a<n){
            temp = temp -> next;
            a++;
        }

        while(temp -> next!=NULL){
            pr=s;
            s=s-> next;
            temp = temp -> next;
        }
        if(pr!=NULL){
             pr -> next = s-> next;
        delete(s);
        return head;
        }
       else{
           s= s-> next;
           return s;
       }
        
    }


    
int main(){
    Node* node1 = new Node(63);
    

    Node* head = node1;
    
   
    
    InsertAtHead(head, 50);
    InsertAtHead(head, 40);
    InsertAtHead(head, 30);
     InsertAtHead(head, 20);
    print(head);
    cout<<endl;
   

    print(removeNthFromEnd(head,4));
    
    return 0;	
}
