// https://leetcode.com/problems/peak-index-in-a-mountain-array/


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = 0;
        
        for(int i = 0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1]){
                ans = i;
                break;
            }
        }
        return ans;
    }
};