
/*
    author: MrS4g0
    created: 24.07.2021 14:27:14
*/

#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using LD = long double;

using vi = vector<int>;
using vll = vector<LL>;
using vull = vector<ULL>;
using vb = vector<bool>;
using pii = pair<int,int>;
using Graph = vector<vi>;

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }

constexpr int MOD = (int)1e9 + 7;


void solve() {
    double ans = nxt() * 1.0 / 3;
    double f = floor(ans);
    double c = ceil(ans);
    if (abs(ans - f) < 0.5) {
        cout << int(c) << ' ' << int(f) << '\n';
    } else {
        cout << int(f) << ' ' << int(c) << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

