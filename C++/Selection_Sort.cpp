// Github username: PrathmeshN99
// Aim: Sorting Algorithms selecting the optimal one according to requirement
// Date: 19/10/2022

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 6;
    int arr[] = {5,3,9,1,6,4};
    for (auto i:arr){
        cout << i << " ";
    }
    cout << "\n";
    int mini = 0;
    int k = 0;
    for (int i=0;i<n;i++){
        int k = i;
        mini = INT_MAX;
        for (int j=i;j<n;j++){
            if (mini>arr[j]){
                mini = arr[j];
                k = j;
            }
        }
        swap(arr[i],arr[k]);
    }
    for (auto i:arr){
        cout << i << " ";
    }
}
