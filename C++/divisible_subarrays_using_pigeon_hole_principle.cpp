// Github : vinaypathak07
// Pigeonhole Principle
// Divisible SubArrays
#include <iostream>
#include <cstring>

using namespace std;

#define lol long

lol a[1000005], frequency[1000005];

int main() {

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        memset(frequency, 0, sizeof(frequency));
        frequency[0] = 1;

        lol sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            sum += a[i];
            sum %= n;
            sum = (sum + n) % n; // sum+n because if we encountered negative value
            frequency[sum] += 1;
        }

        lol ans = 0;

        for (int i = 0; i < n; i++) {
            if (frequency[i] > 1) {
                lol m = frequency[i];
                ans += (m * (m - 1)) / 2;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
