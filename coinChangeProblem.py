class Solution(object):
   def coinChange(self, coins, amount):
      if amount == 0 :
         return 0
      if min(coins) > amount:
         return -1
      dp = [-1 for i in range(0, amount + 1)]
      for i in coins:
         if i > len(dp) - 1:
            continue
         dp[i] = 1
         for j in range(i + 1, amount + 1):
            if dp[j - i] == -1:
               continue
            elif dp[j] == -1:
               dp[j] = dp[j - i] + 1
            else:
               dp[j] = min(dp[j], dp[j - i] + 1)
         #print(dp)
      return dp[amount]
ob1 = Solution()
print(ob1.coinChange([1,2,5], 11))
