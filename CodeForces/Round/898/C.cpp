
/*
    author: MrS4g0
    created: 21.09.2023 17:57:02
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using i64 = long long;
using ui64 = unsigned long long;
using ld = long double;

using i128 = __int128;
using ui128 = unsigned __int128;
inline i128 iget() { i64 x; cin >> x; return static_cast<i128>(x); }
inline ui128 uiget() { ui64 x; cin >> x; return static_cast<ui128>(x); }

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


vector<string> m(10);

void solve() {
    for (auto& i : m) {
        cin >> i;
    }

    int res = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = i; j < 10 - i; ++j) {
            if (m[i][j] == 'X') {
                res += i + 1;
            }
            if (m[10 - i - 1][j] == 'X') {
                res += i + 1;
            }
        }

        for (int j = i + 1; j < 10 - i - 1; ++j) {
            if (m[j][i] == 'X') {
                res += i + 1;
            }
            if (m[j][10 - i - 1] == 'X') {
                res += i + 1;
            }
        }
    }

    cout << res << nl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

