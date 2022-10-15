#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number of processes: ";
	cin>>n;
	int bt[n],wt[n],tat[n];
	float avg_wt=0,avg_tat=0;
	cout<<"Enter burst time for "<<n<<" processes: ";
	for(int i=0;i<n;i++)
	{
		cin>>bt[i];
	}
	wt[0]=0;
	cout<<"waiting time for "<<n<<" processes is: "<<endl;
	cout<<"0"<<endl;
	for(int i=1;i<n;i++)
	{
		wt[i]=0;
		for(int j=0;j<i;j++)
		{
			wt[i]+=bt[j];
		}
		avg_wt+=wt[i];
		cout<<wt[i]<<endl;
	}
	cout<<"\nTurn around time for "<<n<<" processes is: "<<endl;
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		avg_tat+=tat[i];
		cout<<tat[i]<<endl;
	}
	avg_wt/=n;
	avg_tat/=n;
	cout<<"Average waiting time for "<<n<<" processes is: "<<avg_wt<<endl;
	cout<<"Average turn around time for "<<n<<" processes is: "<<avg_tat<<endl;
	return 0;
}
