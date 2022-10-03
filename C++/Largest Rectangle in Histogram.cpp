#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        vector<int> l(n),r(n);
        for(int i=0;i<n;i++)
        {
            while(!s.empty()&&heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty())
                l[i]=-1;
            else
                l[i]=s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty()&&heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty())
                r[i]=n;
            else
                r[i]=s.top();
            s.push(i);
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,(r[i]-l[i]-1)*heights[i]);
        }
        return mx;
    }
};

int main()
{
    Solution s=Solution();
    vector<int> v={2,1,5,6,2,3};
    int mx=s.largestRectangleArea(v);
    cout<<"Largest Rectangle in Histogram is:"<<mx;
    return 0;
} 