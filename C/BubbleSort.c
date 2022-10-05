// Prianshu Prasad - https://github.com/rphrp1985

#include <stdio.h>

void printArray(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void BubbleSort(int *A,int n)
{
    int temp,flag=1;
    for(int i=0;i<n-1 && flag;i++)
    {
      flag=0;
      
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j] > A[j+1])
            {
                flag=1;
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {5,7,3,1,2};
    int n = 5;
    printArray(A,n);
    BubbleSort(A,n);
    printArray(A,n);

}

