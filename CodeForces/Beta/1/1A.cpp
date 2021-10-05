
/*
    author: MrS4g0
    created: 16.07.2021 20:52:45
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
    int n, m, a; cin >> n >> m >> a;
    cout << (ULL)ceil(n * 1.0 / a) * (ULL)ceil(m * 1.0 / a) << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = 1; t <= tc; ++t) {
        solve();
    }

    return 0;
}

