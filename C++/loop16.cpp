

#include<bits\stdc++.h>
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int abs(int a)
    {
        if(a>0)
        return a;
        else
        return -1*a;
    }
    int max(int a,int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    void printPattern(int n)
    {
        // Write Your Code here
        for(int i=-1*n+1;i<n;i++)
        {
            for(int j=-1*n+1;j<n;j++)
            {
                cout<<1+max(abs(i),abs(j));
            }
            cout<<endl;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        
        Solution ob;
        ob.printPattern(N);
        
    }
    return 0;
}
// } Driver Code Ends