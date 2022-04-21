
/*
    author: MrS4g0
    created: 02.04.2022 10:27:27
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x01, y01, x02, y02;
    cin >> x01 >> y01 >> x02 >> y02;

    int x11, y11, x12, y12;
    cin >> x11 >> y11 >> x12 >> y12;

    int X0 = min(x01, x11);
    int Y0 = min(y01, y11);
    int X1 = max(x02, x12);
    int Y1 = max(y02, y12);

    cout << static_cast<int>(pow(max((X1 - X0), (Y1 - Y0)), 2)) << nl;

    return 0;
}

