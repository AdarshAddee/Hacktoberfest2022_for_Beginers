#include<stdio.h>
#include<conio.h>
struct node {
 int data;
 struct node *link;
};
struct node *start=NULL;
void Insert();
void Delete();
void Display();
void Search();
int length();
void main()
{
 int ch;
 do
 {
 printf("\n\nMENU");
 printf("\n1 Insert\n2 Delete \n3 Search\n4 Display\n5 Exit");
 printf("\nChoice ? ");
 scanf("%d",&ch);


 switch(ch)
 {
 case 1: Insert(); break;
 case 2: Delete(); break;
 case 3: Search(); break;
 case 4: Display(); break;
 case 5: break;
 default : printf("\nWrong Choice ");
 }
 }while(ch!=5);
 printf("\nThank You ");
} // end of main
int length()
{
 int c=0;
 struct node *p=start;
 while(p!=NULL)
 {
 c++;
 p=p->link;
 }
 return c;
}
void Display()
{
 struct node *p;
 if(start==NULL)
 printf("\nEmpty");


 else
 {
 printf("\nList is \n");
 p=start;
 while(p!=NULL)
 {
 printf("\t%d",p->data);
 p=p->link;
 }
 }
}
void Search()
{
 int item;
 struct node *p;
 if(start==NULL)
 printf("\nEmpty");
 else
 {
 printf("\nEnter the number ");
 scanf("%d",&item);
 p=start;
 while(p!=NULL && p->data!=item)
 p=p->link;
 if(p==NULL)
 printf("\n%d is not found ", item);
 else
 printf("\n%d is found ", item);


 }
}
void Insert()
{
 struct node *p,*n;
 int i,pos;
 printf("\nEnter position ");
 scanf("%d",&pos);
 if(pos<=length()+1)
 {
 n=(struct node *)malloc(sizeof(struct node));
 printf("\nEnter number ");
 scanf("%d",&n->data);
 if(pos==1)
 {
 n->link=start;
 start=n;
 }
 else
 {
 p=start;
 for(i=1;i<pos-1;i++)
 p=p->link;
 n->link=p->link;
 p->link=n;
 }
 printf("\n%d is inserted at %d position ",n->data,pos);
 }


 else
 printf("\nInvalid position");
}
void Delete()
{
 struct node *p,*n;
 int pos,i;
 if(start==NULL)
 printf("\nUNDERFLOW");
 else
 {
 printf("\nEnter the position ");
 scanf("%d",&pos);
 if(pos<=length())
 {
 if(pos==1)
 {
 n=start;
 start=start->link;
 printf("\n%d is deleted from %d position", n->data,pos);
 free(n);
 }
 else
 {
 p=start;
 for(i=1;i<pos-1;i++)
 p=p->link;
 n= p->link;


 p->link = n->link;
 printf("\n%d is deleted from %d position", n->data,pos);
 free(n);
 }
 }
 else
 printf("\nInvalid position");
 }
} //end of Delete
