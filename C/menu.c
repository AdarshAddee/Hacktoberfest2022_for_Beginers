//contributed by ISHITA SINGHAL

#include<stdio.h>  
#include<stdlib.h>  
void beginsert(int);  
void endinsert(int);
void display();
struct node  
{  
    int info;  
    struct node *next;  
};  
struct node *start= NULL; 

struct node *loc;
void main ()  
{  
    int choice,item,x, flag;  
    char ch;
    do{
    printf("choose one option\n 1. insert at beginning\n 2. insert at end \n3. display linked list \n");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
        {
            printf("\nEnter the item which you want to insert?\n");  
            scanf("%d",&item);  
            beginsert(item);  
            break;
        }
        case 2:
        {
            printf("\nEnter the item which you want to insert?\n");  
            scanf("%d",&item);  
            endinsert(item); 
            break;
        }
        case 3:
        {
            display();
            break;
        }
        default:
        {
            printf("Wrong input");
        }
    }
    printf("\nDo you want to continue?(y/n)\n");
    scanf("%s",&ch);
    }while(ch=='y'|| ch=='Y');
      
}  
void beginsert(int item)  
    {  
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        if(temp==NULL){
            return;
        }
        temp->info=item;
        temp->next=NULL;
        if(start==NULL){
            start=temp;
        }
        else{
            temp->next=start;
            start=temp;
        }
        
          
    }  
void endinsert(int item)  
    {  
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        if(temp==NULL){
            return;
        }
        temp->info=item;
        temp->next=NULL;
        if(start==NULL){
            start=temp;
        }
        else{
             loc=(struct node*)malloc(sizeof(struct node));
                loc=start;
                while(loc->next!=NULL){
                    loc=loc->next;
                }
                loc->next=temp;
        }
          
    }  
    
void display()
{
   loc=(struct node*)malloc(sizeof(struct node));
   
   if(loc==NULL){
       return;
   }
   loc=start;
   while(loc!=NULL){
       printf("%d ",loc->info);
       loc=loc->next;
   }
}
