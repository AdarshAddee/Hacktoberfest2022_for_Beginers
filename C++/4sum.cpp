class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.size()<2)
          return res;
       sort(nums.begin(),nums.end()); 
       for(int i=0;i<nums.size()-2;i++)
       {
         if(i==0 || (i!=0 && nums[i]!=nums[i-1]))
         {
           long long temp1 = target-nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
              if(j==i+1 || nums[j]!=nums[j-1])
              {
                 int k=j+1;
                long long sum=temp1-nums[j];
                 int l = nums.size()-1;
                 while(k<l)
                 {
                   if(nums[k]+nums[l]==(sum))
                   {
                     res.push_back({nums[i],nums[j],nums[k],nums[l]});
                     while(k<l && nums[k]==nums[k+1])
                       k++;
                     while(k<l && nums[l]==nums[l-1])
                       l--;        
                     k++;
                     l--;
                   }
                   else if(nums[k]+nums[l]>(sum))
                     l--;
                   else
                     k++;
                 }
              }
            }
         }
       }
      return res;
    }
};
