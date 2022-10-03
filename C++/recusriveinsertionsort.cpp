//Github Username : shrey0902
#include<iostream>
using namespace std;

void insertionsort(int *arr , int n){
//base case - already sorted
 if(n==0 || n==1){
    return;
 }
//Recusirve call
insertionsort(arr , n-1);
//ek case solve krna hai 
int temp = arr[n-1];
int j=n-2;
while(j>=0 && arr[j]>temp)
{
    arr[j+1]=arr[j];
    j--;
}
arr[j+1] =temp;
}

int main (){
    int arr[5]={54,12,76,45,32};

    insertionsort(arr , 5);

    //print the array 
    cout<<"The sorted array is: ";
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0 ;
}