
/*
    author: MrS4g0
    created: 29.07.2021 17:34:10
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
    int n = nxt();
    int last = nxt();
    LL ans = -1;
    for (int i = 1; i < n; ++i) {
        int next = nxt();
        ans = max(ans, last * 1ll * next);
        last = next;
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

