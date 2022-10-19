Name - Srishti Chauhan
Difficulty - Medium
Problem number - 189
Link - https://leetcode.com/study-plan/algorithm/?progress=xmb85m4v

//Code

class Solution:
  def rotate(self, nums: List[int], k: int) -> None:
    k %= len(nums)
    self.reverse(nums, 0, len(nums) - 1)
    self.reverse(nums, 0, k - 1)
    self.reverse(nums, k, len(nums) - 1)
  def reverse(self, nums: List[int], l: int, r: int) -> None:
    while l < r:
      nums[l], nums[r] = nums[r], nums[l]
      l += 1
      r -= 1
        