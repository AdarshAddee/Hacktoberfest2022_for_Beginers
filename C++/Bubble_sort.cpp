#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {13,46,24,52,20,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int j = 1;
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-i;j++) {
        if(arr[j]>arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }}
    }
    for(int i = 0;i<n;i++) {
        cout << arr[i] << " ";
    }
}