#include<iostream>
using namespace  std;

 int main(){

   
    int arr1[6]={ 43,56,76,433,54,7};
    int n1,i,loc=-1;
    cout<<"enter element you want  to scearch"<<"\n";
    cin>>n1;
    for(i = 0; i<6;i++){
        if(arr1[i]==n1){
            loc =i;
        }
    }
    if(loc==-1){
            cout<<"number not exit in list"<<endl;

        }
    else
             cout<<"value found at index number"<<loc<<endl;
    

    return 0;
}
