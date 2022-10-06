#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
void PrintingElements(struct node *lead){
	while(lead!=NULL){
		printf("Element is - %d   [%u]\n",lead->data,lead->link);
		lead=lead->link;
	}
}
bool Search(struct node *lead,int value){
	while(lead->link!=NULL){
		if(lead->data==value)
		return true;
		lead=lead->link;
	}
	if(lead->data==value)
	return true;
	return false;
}
int main(){
	struct node *first,*second,*third;
	
	first=(struct node*)malloc(sizeof(struct node *));
	second=(struct node*)malloc(sizeof(struct node *));
	third=(struct node*)malloc(sizeof(struct node *));
	
	first->data=20;
	second->data=30;
	third->data=40;
	
	first->link=second;
	second->link=third;
	third->link=NULL;
	
	printf("Printing Elements \n");
	PrintingElements(first);
	int value;
	printf("\nEnter the Element to Search for it - ");
	scanf("%d",&value);
	int v=Search(first,value);
	printf("%d",v);
	if(v)
	printf("\nValue found");
	else
	printf("\nValue not found");
	return 0;
}
