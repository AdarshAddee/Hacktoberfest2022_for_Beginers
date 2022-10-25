#include<iostream>
#include<string>
using namespace std;
int main(){
    int i,k,m,n;
    string str[1000];
    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>m>>n;
        
     if(m<n)
     {
         str[i] = "FIRST";
     }
     else if(m>n)
     {
         str[i] = "SECOND";
     }
     else
     {
        str[i] = "ANY";
     }
    }
    
    for(i=0;i<k;i++)
    {
    cout<<str[i]<<endl;
    }
    
	return 0;
}