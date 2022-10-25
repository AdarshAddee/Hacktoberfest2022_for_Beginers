#include <iostream>
using namespace std;

int main() {
	int i,t,a,b,c,d;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>a>>b>>c>>d;
	    if(a>b)
	    {
	        if(c>d)
	        {
	            if(a>c)
	            {
	                cout<<"Q"<<endl;
	            }
	            else if(a<c)
	            {
	                cout<<"P"<<endl;
	            }
	            else
	            cout<<"TIE"<<endl;
	        }
	        else
	        {
	            if(a>d)
	            {
	                cout<<"Q"<<endl;
	            }
	            else if(a<d)
	            {
	                cout<<"P"<<endl;
	            }
	            else
	            cout<<"TIE"<<endl;
	            
	        }
	    }
	    else
	    {
	         if(c>d)
	        {
	            if(b>c)
	            {
	                cout<<"Q"<<endl;
	            }
	            else if(b<c)
	            {
	                cout<<"P"<<endl;
	            }
	            else
	            cout<<"TIE"<<endl;
	        }
	        else
	        {
	            if(b>d)
	            {
	                cout<<"Q"<<endl;
	            }
	            else if(b<d)
	            {
	                cout<<"P"<<endl;
	            }
	            else
	            cout<<"TIE"<<endl;
	            
	        }
	    }
	}
	return 0;
}
