// Github username: Ashwani-de
// Aim: I want to contribute in hacktober fest for get exposure to open-source contribution
// Date: 10/10/2022

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        int lowestPrice = INT_MAX, finalProfit = 0;
        for(int i = 0; i<n; i++){
            if(prices[i]<lowestPrice){
                lowestPrice = prices[i];
            }
            finalProfit = max(finalProfit, prices[i] - lowestPrice);
        }
        return finalProfit;
    }
};

int main(){
    Solution obj;
    vector<int> prices = {7,1, 5, 3, 6, 4 };
    int result = obj.maxProfit(prices);
    cout << result;
    return 0;
}