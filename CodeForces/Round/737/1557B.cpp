
/*
    author: MrS4g0
    created: 09.08.2021 17:53:38
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
    int n, k; cin >> n >> k;
    vi a(n);
    for (auto& it : a) {
        cin >> it;
    }

    if (n == k) {
        cout << "YES\n";
        return;
    }

    vi b(n, 0);
    iota(b.begin(), b.end(), 0);
    sort(b.begin(), b.end(), [&](int i, int j){
        return a[i] < a[j];
    });

    int res = n;
    for (int i = 1; i < n; ++i) {
        if (b[i - 1] + 1 == b[i]) {
            --res;
        }
    }

    cout << (res <= k ? "YES\n" : "NO\n");
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

