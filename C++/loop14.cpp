#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);              	                  // Reading input from STDIN
	       // Writing output to STDOUT
	for(int i=0;i<n;i++)
	{
		if(i==0||i==n-1)
		{
			for(int j=0;j<n;j++)
				printf("*");
		}
        else
        {
            for(int j=i;j<n;j++)
            {
                if(j==n-1)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
	}
}
