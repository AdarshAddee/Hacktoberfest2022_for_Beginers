/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.*/

/*->initialize currMax and max as first element of vector nums
->Run a loop from second element(index 1) in the vector to the last element
->Assign currMax as the maximum of sum of previous elements and the current element
->Assign max to the maximum value of current max
*/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
        int currMax=nums[0],max=nums[0];
        for(int i=1;i<nums.size();i++){
            currMax = std::max(currMax+nums[i],nums[i]);
            max = std::max(currMax,max);
        }
    return max;
    }
int main() { 
   
return 0; 
}

//https://leetcode.com/problems/maximum-subarray/