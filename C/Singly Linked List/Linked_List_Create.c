#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node *addNode(struct node *lead,int item){
	struct node *temp=lead,*newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=item;
	if(lead==NULL){
		lead=newNode;
		lead->next=NULL;
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->next=NULL;	
	}
	return lead;
}

void PrintingElements(struct node*lead){
	struct node*temp=lead;
	while(temp!=NULL){
		printf("Element is - %d\n",temp->data);
		temp=temp->next;
	}
}

int main(){
	struct node *head=NULL;
	head=addNode(head,10);
	head=addNode(head,20);
	head=addNode(head,30);
	
	PrintingElements(head);
	return 0;
}
