#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *InsertingFirst(struct node *lead,int value){
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=value;
	newNode->link=lead;	
	return newNode;
}
struct node *InsertingInBetween1(struct node*lead,int position,int value){
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=value;
	struct node *previous=lead,*next=lead->link;
	int i=1;
	while(i<position-1){
		previous=previous->link;
		next=next->link;
		i++;
	}
	newNode->link=previous->link;	
	previous->link=newNode;
	return lead;	
}

struct node *InsertingInBetween2(struct node*lead,int position,int value){
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=value;
	struct node *previous=lead,*next=lead->link;
	int i=1;
	while(i<position-1){
		previous=previous->link;
		next=next->link;
		i++;
	}
	newNode->link=previous->link;	
	previous->link=newNode;
	return lead;	
}

struct node *InsertingEnd(node *first,int value){
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=value;
	struct node*temp=first;
	while(temp->link!=NULL){
		temp=temp->link;
	}
	temp->link=newNode;
	newNode->link=NULL;
	return first;
}
int PrintingElements(struct node* lead){
	while(lead!=NULL){
		printf("Element is - %d",lead->data);
		lead=lead->link;
	}
	return 0;
}
int main(){
	struct node *first,*second,*third;
	
	first=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	
	first->data=20;
	second->data=30;
	third->data=40;
	
	first->link=second;
	second->link=third;
	third->link=NULL;
	printf("Printing Elements before Inserting\n");
	PrintingElements(first);
	
	int value;
	printf("\nEnter Element to insert at beginning of the node - ");
	scanf("%d",&value);
	
	first=InsertingFirst(first,value);
	
	printf("\nPrinting Elements after Inserting\n");
	PrintingElements(first);
	
	int position;
	printf("\nEnter Element to insert in Between the Linked List - ");
	scanf("%d",&value);
	printf("Enter the position -");
	scanf("%d",&position);
	
	first=InsertingInBetween2(first,position,value);	
	
	printf("\nPrinting Elements after Inserting\n");
	PrintingElements(first);
	
	printf("\nEnter Element to insert at the end of the node - ");
	scanf("%d",&value);
	first=InsertingEnd(first,value);
	
	printf("\nPrinting Elements after Inserting\n");
	PrintingElements(first);
	return 0;
}
