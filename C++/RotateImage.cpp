//GitHub UserName ---> thisisharsh7

#include<iostream>

using namespace std;

int main(){
    int arr[100][100];
    int n;
    cin>>n;
    int x=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=x;
            x+=1;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(arr[i][j],arr[i][n-j-1]);
        }
    }
    // for(int i=0;i<n-1;i++){
    //     for(int j=n-1;j>i;j--){
    //         swap(arr[i][j],arr[j][i]);
    //     }
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
    cout<<endl;
    cout<<"Rotated Array is ::::"<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}