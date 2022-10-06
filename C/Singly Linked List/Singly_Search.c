#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
void Search(struct node *lead,int value){
	int v=0;
	while(lead->link!=NULL){
		if(lead->data==value){
			v=1;
		}
		lead=lead->link;
	}
	if(lead->data==value)
	v=1;	
	if(v==0)
	printf("Not Found");
	else
	printf("Found");
}
int main(){
	struct node *first=(struct node*)malloc(sizeof(struct node));
	struct node *second=(struct node*)malloc(sizeof(struct node));
	
	first->data=10;
	second->data=20;
	
	first->link=second;
	second->link=NULL;
	
	Search(first,20);
	
	
}
