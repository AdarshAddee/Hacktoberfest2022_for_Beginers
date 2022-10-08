/*
    Github Username : Shivam-3001
    Authors Name : Shivam Thakur
    Date Modified: 8 October, 2022
*/
// C++ program to find element in an array using linear search

#include<iostream>
using namespace std;

//function to traverse the array and match every element to key
int linearSearch(int arr[], int n, int key){
    int ans=-1;
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            ans=i;
            break;
        }
    }
    return ans;
}

int main(){
    int n, key;
    cout<<"Enter the number of elements and key:"<<endl;
    //n--> number of elements and k-->key
    cin>>n>>key;
    int arr[n];
    //input array elements
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"Element is found at index: "<<linearSearch(arr, n, key);
    return 0;
}