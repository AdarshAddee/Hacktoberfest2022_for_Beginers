// contributed by ISHITA SINGHAL

#include <stdio.h>

int main() {
	//code
	int arr[100];
	printf("enter no of elements:");
	int a;
	scanf("%d",&a);
	printf("enter elements:");
	for(int i=0;i<a;i++){
	    scanf("%d",&arr[i]);
	}
	printf("enter element to be found:");
	int c,flag=0;
	scanf("%d",&c);
		for(int i=0;i<a;i++){
		    if(arr[i]==c){
		        printf("element found at index %d",i);
		        flag=1;
		        break;
		    }
		}
		if(flag==0)
		printf("element not present");
	return 0;
}
