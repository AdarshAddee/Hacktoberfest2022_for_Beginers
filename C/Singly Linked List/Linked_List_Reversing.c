#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *reverse(struct node *lead){
	struct node *curr=NULL,*nextR=NULL;
	while(lead!=NULL){
		nextR=lead->next;
		lead->next=curr;
		curr=lead;
		lead=nextR;
	}
	return curr;
};

void PrintingElements(struct node *lead){
	while(lead!=NULL){
		printf("Element is - %d   [%u]\n",lead->data,lead->next);
		lead=lead->next;
	}
}

int main(){
	struct node *first,*second,*third,*fourth;
	first=(struct node *)malloc(sizeof(struct node));
	second=(struct node *)malloc(sizeof(struct node));
	third=(struct node *)malloc(sizeof(struct node));
	fourth=(struct node *)malloc(sizeof(struct node));
	
	first->data=10;
	second->data=20;
	third->data=30;
	fourth->data=40;
	
	first->next=second;
	second->next=third;
	third->next=fourth;
	fourth->next=NULL;
	
	first=reverse(first);
	PrintingElements(first);
	return 0;
}
