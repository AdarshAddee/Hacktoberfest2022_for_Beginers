#include<iostream>
using namespace std;

void bubblesort(int *arr,int size){
    //base case
    
    if(size ==0 || size==1){
        return;
    }

    //sorting algo
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    //recursion
    bubblesort(arr,size-1);
}



int main(){
    int arr[5]={4,16,8,9,6};
   
    
    bubblesort(arr,5);
    
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    

}
