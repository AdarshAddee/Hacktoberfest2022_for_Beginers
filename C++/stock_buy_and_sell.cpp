#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> prices)
{
    int profit = 0;
    int minV = prices[0];
    int maxProfit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        minV = min(minV, prices[i]);
        profit = prices[i] - minV;
        maxProfit = max(profit, maxProfit);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
}
