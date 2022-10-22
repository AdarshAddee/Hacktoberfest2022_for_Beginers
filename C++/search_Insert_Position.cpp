// Problem Link : https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int l = 0;
        int h = nums.size() - 1;
        if(target > nums[h])
        {
            return h + 1;
        }
        else if(target < nums[l])
        {
            return l;
        }
        else
        {
            while(l <= h)
            {
                int mid = l + (h - l)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target)
                {
                    if(nums[mid - 1] < target)
                    {
                        return mid;
                    }
                    else
                    {
                        h = mid - 1;
                    }
                }
                else
                {
                    if(nums[mid + 1] > target)
                    {
                        return mid + 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};
