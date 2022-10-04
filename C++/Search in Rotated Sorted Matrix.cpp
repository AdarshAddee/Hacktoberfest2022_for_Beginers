class Solution {
public:
    int search(vector<int>& nums, int target)
    {
       //binary search
        int l=0;
        int n= nums.size();
        int r = n-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[l]<=nums[mid]) //left sorted
            {
               if(nums[l]<=target && nums[mid]>target)
               {
                   r = mid-1;
               }
                else
                    l = mid+1;
            }
            else //right sorted
            {
              if(nums[mid]<target && nums[r]>=target)
              {
                  l=  mid+1;
               }
                else
                    r=mid-1;
                    
            }
        }
        return -1;
    }
};
