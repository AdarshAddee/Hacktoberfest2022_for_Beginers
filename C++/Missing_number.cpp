#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int missingNumber(vector<int>& nums, int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=ans^i;
        }
        for(int i=0;i<n;i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
