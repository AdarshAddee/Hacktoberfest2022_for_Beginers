#include <bits/stdc++.h>
using namespace std;

int count(int coins[], int n, int sum)
{
    int table[sum + 1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
 
    for (int i = 0; i < n; i++){
        for (int j = coins[i]; j <= sum; j++){
            table[j] += table[j - coins[i]];
        }
    }
    return table[sum];
}
 
int main()
{
    int coins[] = { 1, 2, 3};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 4;
    cout << count(coins, n, sum);
    return 0;
}