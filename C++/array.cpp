#include <iostream>
using namespace std;
int main()
{
	int a[10]={3,2,4,5,6,4,9,7,8,1};
	int max=a[0];
	int min=a[0];
	
	for (int i=1;i<=10;i++)
	{
		if (a[i]>max)
			max=a[i];
		else if (a[i]<min)
			min=a[i];
		
	}
	cout<<"Max value is :"<<max<<endl;
	cout<<"Min value is :"<<min<<endl;
return 0;
}
