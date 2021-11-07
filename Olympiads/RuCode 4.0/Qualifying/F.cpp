
/*
    author: MrS4g0
    created: 07.11.2021 21:12:35
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using i64 = long long;
using ui64 = unsigned long long;
using ld = long double;

// using i128 = __int128;
// using ui128 = unsigned __int128;
// inline i128 iget() { i64 x; cin >> x; return (i128)x; }
// inline ui128 uiget() { ui64 x; cin >> x; return (ui128)x; }

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vi64 = vector<i64>;
using vui64 = vector<ui64>;

using pi = pair<int,int>;
using pi64 = pair<i64,i64>;
using pui64 = pair<ui64,ui64>;
using graph = vector<vi>;

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }

constexpr int MOD = int(1e9) + 7;
constexpr int NMOD = 998244353;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = nxt();
    vi dp(N + 1);
    vi res;

    for (int i = 2; i < N + 1; ++i) {
        int mn = dp[i - 1] + 1;
        if (i % 4 == 0) {
            mn = min(mn, dp[i / 4] + 1);
        }
        if (i % 5 == 0) {
            mn = min(mn, dp[i / 5] + 1);
        }
        dp[i] = mn;
    }

    res.push_back(N);
    for (int i = N; i > 1;) {
        if (dp[i] == dp[i - 1] + 1) {
            res.push_back(--i);
            continue;
        }
        if (i % 4 == 0 && dp[i] == dp[i / 4] + 1) {
            res.push_back(i /= 4);
            continue;
        }
        res.push_back(i /= 5);
    }

    cout << res.size() - 1 << nl;
    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        cout << *it << ' ';
    }

    return 0;
}

