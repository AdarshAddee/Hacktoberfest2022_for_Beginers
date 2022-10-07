#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int t){
    int low = 0, high = n-1; 
    while(high>=low){
        int mid = (high+low)/2;
        if(arr[mid]==t){
            return mid;
        }
        else if(arr[mid]>t){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int t, int n, int low, int high){
    if(low>high){
        return -1;
    }
    int mid = (high+low)/2;
    if(arr[mid] == t){
        return mid;
    }
    else if(arr[mid]>t){
        return binarySearch(arr, t, n, low, mid - 1);
    }
    else {
        return binarySearch(arr, t, n, mid + 1, high);
    }
}

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    cout<<binarySearch(arr, 5, 30)<<endl;
    cout<<binarySearch(arr, 30, 5, 0, 4)<<endl;
    return 0;
}