
/*
    author: MrS4g0
    created: 16.11.2021 10:40:02
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


int BinSearch(vi& v, int a) {
    int l = -1, r = (int)v.size();
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        if (v[m] <= a) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = nxt();
    vi v(n);
    for (auto& it : v) {
        it = nxt();
    }
    sort(v.begin(), v.end());

    int k = nxt();
    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
        cout << BinSearch(v, r) - BinSearch(v, l - 1) << ' ';
    }

    return 0;
}

