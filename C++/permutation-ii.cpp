// Github username: deepak089
// Aim: i want to add recursion program for finding permutation consisting of unique element.
// Date: 17-10.2022
// start coding

class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&v,int i)
    {
        if(i>=nums.size())
        {
            v.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            if(j>i && nums[j]==nums[j-1]) continue;
            swap(nums[i],nums[j]);
            solve(nums,v,i+1);
            swap(nums[i],nums[j]);
        }
          
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        solve(nums,v,0);
        return v;
    }
};