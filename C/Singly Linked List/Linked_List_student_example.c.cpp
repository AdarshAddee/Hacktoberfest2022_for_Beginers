#include<stdio.h>
struct student{
	int rollno;
	char name[30];
	int total_marks;
	
	struct student *next;
};
int main(){
	struct student s1,s2,s3,*ptr;
	printf("Enter student 1 Details - ");
	printf("\nEnter Roll No. - ");
	scanf("%d",&s1.rollno);
	printf("Enter Name of the student - ");
	scanf("%s",s1.name);
	printf("Enter Total Marks - ");
	scanf("%d",&s1.total_marks);
	
	printf("\nEnter student 2 Details - ");
	printf("\nEnter Roll No. - ");
	scanf("%d",&s2.rollno);
	printf("Enter Name of the student - ");
	scanf("%s",s2.name);
	printf("Enter Total Marks - ");
	scanf("%d",&s2.total_marks);
	
	printf("\nEnter student 3 Details - ");
	printf("\nEnter Roll No. - ");
	scanf("%d",&s3.rollno);
	printf("Enter Name of the student - ");
	scanf("%s",s3.name);
	printf("Enter Total Marks - ");
	scanf("%d",&s3.total_marks);
	
	//Referal address to each student objects
	s1.next=&s2;
	s2.next=&s3;
	s3.next=NULL;
	
	//printing Elements
	printf("\n\n");
	ptr=&s1;
	while(ptr!=NULL){
		printf("Total Marks of %s (Roll No. - %d) = %d\n",ptr->name,ptr->rollno,ptr->total_marks);
		ptr=ptr->next;
	}
	
	return 0;
}
