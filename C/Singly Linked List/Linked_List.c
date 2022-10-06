#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int main(){
	struct node *head,*middle,*last;
	head=(struct node *)malloc(sizeof(struct node));
	middle=(struct node *)malloc(sizeof(struct node));
	last=(struct node *)malloc(sizeof(struct node));
	
	head->data=10;
	middle->data=20;
	last->data=30;
	
	head->next=middle;
	middle->next=last;
	last->next=NULL;
	
	//printing data Elements
	struct node *print=head;
	while(print!=NULL){
		printf("%d\n",print->data);
		print=print->next;
	}
	return 0;
}
