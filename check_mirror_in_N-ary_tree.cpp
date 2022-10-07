//Check Mirror in N-ary tree
//https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1#

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int a[], int b[]) {
        // code here
        vector<vector<int>> adj(n+1);
        
        for(int i=0;i<2*e;i+=2)
            adj[a[i]].push_back(a[i+1]);
            
        for(int i=0;i<2*e;i+=2){
            int u=b[i], v=b[i+1];
            
            if(adj[u].size()==0 || adj[u].back()!=v)
                return 0;
                
            adj[u].pop_back();
        }
        
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends