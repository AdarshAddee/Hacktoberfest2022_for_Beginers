// Username - nutnick31
// Q - Print 1 to 100 without using numbers
// 16 October 2022

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    char nums = ' ';
    int x = 0;
    for(int i = 0 ; i < 100 ; i++)
    {
    	nums++;
    	if((nums-' ')>0)
    	{
        	cout<<nums-' '<<" ";
        	x = nums-' ';
        }
        else
        	cout<<++x<<" ";
    }
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}