// A simple program  written in c to reverse the number and to check if the number is palindrome or not

#include<stdio.h>


int main(){
	int num;

	printf("enter the number: ");
	scanf("%d",&num);

	int check= num;

	int rem=0;
	int rev;
    
	while(num!=0){
		rem= num%10;
		rev= rev*10 +rem;
		num/=10;
	}
	printf("the reverse of number is: %d",rev);
	
	
	if(rev==check){
		printf("\n the number is palindrome !!");
	}
	
	else{
		printf("\n the number is not palindrome!!!");
	}
	return 0;
}
