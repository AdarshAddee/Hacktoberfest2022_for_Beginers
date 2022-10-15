#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
 Node *reverse(Node* h1)
   {
       Node* next=h1;
       Node *prev=NULL,*curr=NULL;
       while(next)
       {
           curr=next;
           next=next->next;
           curr->next=prev;
           prev=curr;
       }
       return curr;
   }

void reorderList(Node* head) {
  Node *slow=head,*fast=head;
  // step 1 find mid
  while(fast && fast->next)
  {
      slow=slow->next;
      fast=fast->next->next;
  }
  //reverse the 2nd half and split the list
  Node* l1=head;
  Node *l2=reverse(slow->next);
  slow->next=NULL;
  // merge the list;
  while(l2!=NULL)
 { 
   Node *tmp1=l1->next;   
   Node *tmp2=l2->next;
   l1->next=l2;
   l2->next=tmp1;
   l1=tmp1;
   l2=tmp2;
 }
   
};