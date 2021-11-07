
/*
    author: MrS4g0
    created: 07.11.2021 19:16:33
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

ld eps = 1e-10;
int a, b, c, d, e, f;

inline ld fx(ld x) {
    ld ans = a*pow(x,5) + b*pow(x,4) + c*pow(x,3) + d*x*x - e*x - f;
    return ans;
}

inline ld fxp(ld x) {
    ld ans = 5*a*pow(x,4) + 4*b*pow(x,3) + 3*c*x*x + 2*d*x - e;
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c >> d >> e >> f;

    ld x = 0.0;
    while (abs(fx(x)) > eps) {
        x = x - fx(x) / fxp(x);
    }

    cout << fixed << setprecision(10) << x << nl;

    return 0;
}

