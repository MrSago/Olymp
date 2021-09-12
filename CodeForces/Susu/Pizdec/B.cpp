
/*
    author: MrS4g0
    created: 11.09.2021 16:24:57
*/

#include <iostream>
#include <vector>
using namespace std;


vector<vector<int8_t>> dp;
vector<int16_t> arr;
int n;
int k;


bool check(int i, int m) {
    m = ((m % k) + k) % k;

    if (i == n) {
        if (m == 0) {
            return true;
        }
        return false;
    }

    if (dp[i][m] != -1) {
        return dp[i][m];
    }

    return (dp[i][m] = check(i + 1, m + arr[i]) || check(i + 1, m - arr[i]));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    arr.resize(n);
    for (int16_t i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dp.resize(n + 1, vector<int8_t>(k, -1));
    cout << (check(1, arr[0]) ? "Divisible\n" : "Not divisible\n");

    return 0;
}

