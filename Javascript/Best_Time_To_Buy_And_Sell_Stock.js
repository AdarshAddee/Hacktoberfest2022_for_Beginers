// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Solution By Emmanuel Ezenwigbo
/* Time Complexity - O(n)
   Space Complexity - O(1)
*/

var maxProfit = function(prices) {
    let [min_price, maxP] = [Infinity,0];
    
    for (let i = 0; i < prices.length; i++){
        max_sell = prices[i] - min_price
        maxP = Math.max(maxP, max_sell)
        min_price = Math.min(min_price, prices[i])
    }
    
    return maxP;
};