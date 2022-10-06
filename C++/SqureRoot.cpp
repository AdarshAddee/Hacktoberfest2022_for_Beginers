#include <bits/stdc++.h>

using namespace std;

int get(int n)
{
    int start = 0, end = n;
    int mid = (start + end) / 2;
    int ans = 0;
    while (start <= end)
    {

        int sq = mid * mid;
        if (sq == n)
        {
            return mid;
        }
        else if (sq < n)
        {
            ans = end;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = (end + start) / 2;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int b = get(n);
    cout << b;
}
