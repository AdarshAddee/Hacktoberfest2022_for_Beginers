#include<iostream>
using namespace std;
int main(){
    cout<<"Enter number"<<endl;
    int n;
    cin>>n;
    int k=0;
    //upper half
    for(int i=0;i<n;i++){
       for(int j=0;j<n-i;j++){
           cout<<" ";
       }
       while(k!=(2*i)){
        if(k==0||k==2*i-1){
            cout<<"*";
            
        }
        else{
            cout<<" ";
        }
        k++;
       }
       k=0;    
       cout<<endl;
    }
    n--;
    //lower half
    for(int i=n;i>0;i--){
       for(int j=1;j<=n-i;j++){
        cout<< " ";
       }
       k=0;
       while(k!=(2*i-1)){
        if(k==0||k==2*i-2){
            cout<<"*";
        }
        else{
            cout<<" ";
        }
        k++;
       }
     cout<<endl;
    }
    return 0;
}
