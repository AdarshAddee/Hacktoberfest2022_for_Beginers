//GitHub username : 525tamanna
//Aim : To print zig-zag pattern
//Date : 04/10/2022


#include<iostream>
using namespace std;

int main(){
  
  int n;
  cin>>n;
  
  for(int row=1;row<=3;row++){
    for(int col=1;col<=n;col++){
      if( (row + col)%4==0) || (row==2 && col%4==0) ){
        cout<<"*";
      }
      else{
        cout<<" ";
      }
    }
    cout<<endl;
  }
  
  return 0;
}
