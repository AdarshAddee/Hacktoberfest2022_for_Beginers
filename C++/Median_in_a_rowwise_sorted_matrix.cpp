// username : amankushwaha008
// to add median of row wise sorted matrix`s solution to your repository
//date : 11 Oct 2022



// Median in a row-wise sorted Matrix

/*
Given a row wise sorted matrix of size RxC where R and C are always odd, 
find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2

Time Complexity: O(32 * R * log(C))
Auxiliary Space: O(1)
*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{ 
private:
    int search(int target, vector<int> &v, int n)
    {
        int count=0, low=0, high=n-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(v[mid]<=target)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
    int binarySearch(int target, vector<vector<int>> &matrix, int r,int c)
    {
        int count=0;
        for(int i=0; i<r; i++)
        {
            count+=search(target, matrix[i], c);
        }
        return count;
    }
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here      
        int low=1, high=2000, total  = r*c;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int count = binarySearch(mid, matrix, r, c);
            if(count>total/2)
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends