#include<stdio.h>
#include<stdlib.h>
 
void printarray(int num, int a[]){
    for (int i = 0; i < num; i++)
        printf("%d   ", a[i]);
    printf("\n");
}
int maximumvalue(int arr[], int count){
    int m=0;
    for (int i = 0; i < count; i++)
    {
        if(arr[i]>m)
            m=arr[i];
    }
    return m;
}
void Count_Sort(int A[], int num, int p){
    int max=(A[0]/p)%10;
    int output[num];
    int count=num;
    for (int i = 0; i < count; i++)
    {
        if(((A[i]/p)%10)>max){
            max=(A[i]/p)%10;
        }
    }
    
    int C[max+1];
    for(int i=0; i<=max;i++){
        C[i]=0;
    }
    for (int i = 0; i < count; i++)
        C[(A[i]/p)%10]+=1;
    for (int i = 1; i <=max; i++)
        C[i]=C[i]+C[i-1];
    for (int i = count-1; i >=0; i--)
    {
        output[C[(A[i]/p)%10]-1]=A[i];
        C[(A[i]/p)%10]--;
    }
    for (int i = 0; i < count; i++)
        A[i]=output[i];
}

void RadixSort(int A[], int count){
    int max_ele= maximumvalue( A, count);
    for(int p=1; max_ele/p>0; p=p*10){
        Count_Sort(A,count,p);
    }
}
int main(){
    
    int array[8]={170, 45, 75, 90, 802, 24, 2, 66 };
    printf("Array in question :\n");
    printarray(8, array);
    RadixSort(array, 8);
    printf("Sorted Array  :\n");
    printarray(8, array);
}
