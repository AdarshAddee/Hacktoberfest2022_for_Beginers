// C++ program to check whether a number is a
// Sphenic number or not
#include<bits/stdc++.h>
using namespace std;
//create a global array of size 10001;
bool arr[1001];
// This functions finds all primes smaller than 'limit'
// using simple sieve of eratosthenes.
void simpleSieve()
{
	// initialize all entries of it as true. A value
	// in mark[p] will finally be false if 'p' is Not
	// a prime, else true.
	memset(arr,true,sizeof(arr));

	// One by one traverse all numbers so that their
	// multiples can be marked as composite.
	for(int p=2;p*p<1001;p++)
	{
		// If p is not changed, then it is a prime
		if(arr[p])
		{// Update all multiples of p
			for(int i=p*2;i<1001;i=i+p)
			arr[i]=false;
		}
	}
}
int find_sphene(int N)
{
	int arr1[8]={0}; //to store the 8 divisors
	int count=0;	 //to count the number of divisor
	int j=0;
	for(int i=1;i<=N;i++)	
	{
		if(N%i==0 &&count<9)	
		{
			count++;
			arr1[j++]=i;
		}
	}
	//finally check if there re 8 divisor and all the numbers are distinct prime no return 1
	//else return 0
	if(count==8 && (arr[arr1[1]] && arr[arr1[2]] && arr[arr1[3]]))
	return 1;
	return 0;
}

// Driver program to test above function
int main()
{
	int n = 60;
	simpleSieve();
	int ans=find_sphene(n);
	if(ans)
	cout<<"Yes";
	else
	cout<<"NO";
}
