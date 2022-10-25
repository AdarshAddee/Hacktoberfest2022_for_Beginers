#include <iostream>
using namespace std;

int main() {
	int i,k,m,n;
    string str[1000];
    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>m>>n;
        
     if(m==n && m>0 && n>0)
     {
         str[i] = "YES";
     }
     else
     {
        str[i] = "NO";
     }
    }
    
    for(i=0;i<k;i++)
    {
    cout<<str[i]<<endl;
    }
    
	return 0;
}
