#include <iostream>
using namespace std;
int fun(int n)
{
    int j;
    int count=0;
    char str[10000];
    for(j=0;j<n;j++)
    {
        cin>>str[j];
    }
    for(j=0;j<n;j++)
    {
      
        if(str[j]==str[j+1])
        {
            count = count+1;
        }
    }
   return count;
    
   
}
int main() {
	int i,t,n;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n;
	    cout<<fun(n)<<endl;
	}
	return 0;
}
