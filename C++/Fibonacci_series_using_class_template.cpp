// Github username:  CoderKartik-1
// Aim - Building a C++ program using principles of class inheritance to print fibonacci series
// Date - 25/10/2022

#include<iostream>
using namespace std;
class series1
{
	protected:
		int a,b,num;
};
class series2:public series1
{
	protected:
		int t,j;
};
class series3:public series2
{
	public:
		void input()
		{
			a=0;
			b=1;
			cout<<"enter the number : "<<endl;
			cin>>num;
			cout<<"the fb series is : "<<a<<" "<<b<<" ";
		}
		public:
			void show()
			{
				for(j=3; j<=num; j++)
				{
					t=a+b;
					cout<<t<<" ";
					a=b;
					b=t;
				}
			}
};
int main()
{
	series3 obj;
	obj.input();
	obj.show();
}

// Sample Input - 8

// Sample Output:
// the fb series is : 0 1 1 2 3 5 8 13