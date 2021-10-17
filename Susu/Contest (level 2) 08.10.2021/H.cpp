
/*
    author: MrS4g0
    created: 10.10.2021 16:34:43
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
    i64 x[10000];
    i64 n, k;
    cin >> n >> k;
    for (i64 i = 0; i < n; ++i) {
        cin >> x[i];
    }

    i64 r;
    r = x[0];
    for (i64 i = 1; i < n; ++i) {
        if (x[i] > r) {
            r = x[i];
        }
    }

    i64 l = 1, ans = 0;
    while (l <= r) {
        i64 m = (l + r) >> 1;
        i64 j = 0;
        for (i64 i = 0; i < n; ++i) {
            j = j + x[i] / m;
        }
        if (j >= k && m > ans) {
            ans = m;
        }
        if (j >= k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << ans << nl;

    return 0;
}

