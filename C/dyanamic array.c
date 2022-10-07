#include<stdio.h>
int main(){
	int *ptr,i,n;
	printf("Enter n: ");
	scanf("%d",&n);
	ptr = (int *)malloc(n*sizeof(int));
	for (i=0;i<n
	;i++){
		printf("\nEnter element %d: ",i+1);
		scanf("%d",ptr+i);
	}
	for (i=0;i<n;i++){
		printf("\n Element %d: %d ",i+1,*(ptr+i));
		
	}
		
}
