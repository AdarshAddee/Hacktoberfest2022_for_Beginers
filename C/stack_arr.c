#include<stdio.h>
#define MAX 1000

int main(){
	int stack[MAX];
	int size,ele,ch,top = -1;
	printf("Enter size of stack : ");
	scanf("%d",&size);
	while(1){
		printf("\n\n0. Exit\n1. Push\n2. Pop\n3. Display\nEnter choice : ");
		scanf("%d",&ch);
        if(!ch) break;
		switch(ch){
			case 1:
				printf("Enter element : ");
				scanf("%d",&ele);
				if(top < size-1){
					top++;
					stack[top] = ele;
				}
				else printf("\nStack Overflow!\n");
				break;
			case 2:
				if(top >-1){
					printf("Popped element : %d",stack[top]);
					top--;
				}
				else printf("\nStack Underflow!\n");
				break;
			case 3:
				if(top>-1){
					for(ch = top; ch>-1;ch--){
						if(ch==top) printf("%d <--top\n",stack[ch]);
						else printf("%d\n",stack[ch]);
					}
				}
				else printf("Empty stack!!!");
				break;
			default:
				printf("\nWrong Choice!!!\n");
		}
	}
	
	return 0;
}
