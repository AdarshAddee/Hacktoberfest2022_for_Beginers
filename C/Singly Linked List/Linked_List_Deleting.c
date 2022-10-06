#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *DeleteFirst(struct node *head){
	struct node*temp=head;
	head=head->link;
	free(temp);
	return head;
	
};

struct node *DeletingLast(struct node *first){
	struct node *previous=first,*last=first->link;
	while(last->link!=NULL){
		previous=previous->link;
		last=last->link;
	}
	previous->link=NULL;
	free(last);
	
	return first;	
	
};

struct node *DeletingInBetween(struct node *first,int position){
	struct node *previous=first,*current=first->link;
	int i=1; //Get the essence why i=1 and position-1 with diagram
	while(i<position-1){
		previous=previous->link;
		current=current->link;
		i++;
	}	
	previous->link=current->link;
	free(current);
	
	return first;	
};

struct node *DeletingWithValue(struct node *first,int value){
	struct node *pre=first,*curr=first->link;
	while(curr->data!=value){
		pre=pre->link;
		curr=curr->link;
	}	
	pre->link=curr->link;
	free(curr);
	return first;
};

void PrintingElements(struct node *lead){
	while(lead!=NULL){
		printf("Element is - %d   [%u]\n",lead->data,lead->link);
		lead=lead->link;
	}
}

int main(){
	struct node *first,*second,*third,*fourth,*fifth,*sixth;
	
	first=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	fourth=(struct node*)malloc(sizeof(struct node));
	fifth=(struct node*)malloc(sizeof(struct node));
	sixth=(struct node*)malloc(sizeof(struct node));
		
	first->data=20;
	second->data=30;
	third->data=40;
	fourth->data=50;
	fifth->data=60;
	sixth->data=70;
	
	first->link=second;
	second->link=third;
	third->link=fourth;
	fourth->link=fifth;
	fifth->link=sixth;
	sixth->link=NULL;
	
	printf("Printing Elements before Deleting\n");
	PrintingElements(first);
	
	first=DeleteFirst(first);
	
	printf("\nPrinting Elements after Deleting first node\n");
	PrintingElements(first);
	
	first=DeletingInBetween(first,2);
	
	printf("\nPrinting Elements after Deleting node in between using Index Value=2\n");
	PrintingElements(first);
	
	first=DeletingWithValue(first,60);
	
	printf("\nPrinting Elements after Deleting node with Value=60\n");
	PrintingElements(first);
	
	first =DeletingLast(first);
	
	printf("\nPrinting Elements after Deleting Last Node\n");
	PrintingElements(first);
	
	return 0;
}
