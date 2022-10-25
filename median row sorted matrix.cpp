#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){ 
        int min_ele=matrix[0][0],max_ele=matrix[0][c-1];
        for(int i=1;i<r;i++){
            min_ele=min(min_ele,matrix[i][0]);
            max_ele=max(max_ele,matrix[i][c-1]);
        }
        int medpos=(r*c+1)/2;
        while(min_ele<max_ele){
            int mid=(min_ele+max_ele)/2;
            int ele=0;
            for(int i=0;i<r;i++)
            ele+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            if(ele<medpos)
            min_ele=mid+1;
            else
            max_ele=mid;
        }
        return max_ele;
    }
};
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
