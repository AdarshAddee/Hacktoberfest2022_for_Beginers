// leetcode question number : 33
//question level : medium

/*
    Github username: SovanRoy10
    Aim: My aim is to give the correct solution of search in rotated sorted array (leetcode question no 33)
    Date: 19 October, 2023
*/

// solution : 
class Solution
{
    public:
        int pivot(vector<int> &nums)
        {
            int s = 0, l = nums.size() - 1;
            while (s < l)
            {
                int mid = s + (l - s) / 2;
                if (nums[mid] < nums[0])
                    l = mid;
                else
                    s = mid + 1;
            }
            return l;
        }
    int binary_search(vector<int> &nums, int s, int l, int target)
    {
        while (s <= l)
        {
            int mid = s + (l - s) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                s = mid + 1;
            else
                l = mid - 1;
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int pivot_index = pivot(nums);
        int ans = binary_search(nums, 0, pivot_index - 1, target);
        if (ans != -1)
            return ans;
        return binary_search(nums, pivot_index, nums.size() - 1, target);
    }
};

// video solution : https://www.youtube.com/watch?v=iXLMMbdjeNM