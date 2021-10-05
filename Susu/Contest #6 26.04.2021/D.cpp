
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[(int)2e5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> dp(n, 0);
        for (int i = n - 1, j = i + a[i]; i >= 0; --i, j = i + a[i]) {
            dp[i] = j < n ? a[i] + dp[j] : a[i];
        }

        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }

    return 0;
}

