
/*
    author: MrS4g0
    created: 30.07.2021 11:44:13
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
    int n, m; cin >> n >> m;
    if (n > m) {
        cout << "0\n";
        return;
    }
    ++m;
    int ans = 0;
    for (int i = 31; i >= 0 && n < m; --i) {
        if ((n >> i & 1) == (m >> i & 1)){
            continue;
        }
        if (m >> i & 1) {
            ans |= 1 << i;
            n |= 1 << i;
        }
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

