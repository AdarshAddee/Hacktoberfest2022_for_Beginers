#include<bits/stdc++.h>
 
using namespace std;
 
struct node {
    int data;
    struct node *next;
};
 
// We construct a linked list and use this function to push elements to the list 
void push(struct node **head_ref, int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}
 
// Function to reverse the list
void reverse(struct node **head_ref) {
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*head_ref);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}
 
// Checking our program 
void printnodes(struct node *head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
 
// Driver function
int main() {
    struct node *head = NULL;
    push(&head, 28);
    push(&head, 21);
    push(&head, 14);
    push(&head, 7);

    cout << "Original Linked List" << endl;
    printnodes(head);
    reverse(&head);
    cout << endl;
    cout << "Reversed Linked List"<<endl;
    printnodes(head);
    return 0;
}
// github_Username-RiteshKr00