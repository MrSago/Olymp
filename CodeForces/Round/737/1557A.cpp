
/*
    author: MrS4g0
    created: 09.08.2021 17:34:47
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;
using vull = vector<ull>;

using pii = pair<int,int>;
using graph = vector<vi>;

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }

constexpr int MOD = int(1e9) + 7;
constexpr int NMOD = 998244353;


void solve() {
    vi a(nxt());
    for (auto& it : a) {
        cin >> it;
    }
    sort(a.begin(), a.end(), greater<int>());
    
    ll ans = a[0];
    ll sum = 0ll;
    for (int i = 1; i < (int)a.size(); ++i) {
        sum += a[i];
    }

    printf("%.6f\n", ans + sum * 1.0 / (a.size() - 1));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

