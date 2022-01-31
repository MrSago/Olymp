
/*
    author: MrS4g0
    created: 31.01.2022 10:09:28
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


void solve() {
    graph g(nxt());
    for (int i = 1; i < (int)g.size(); ++i) {
        int u = nxt() - 1, v = nxt() - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vi F(g.size()), depth(g.size());

    function<int(int, int)> dfs = [&](int u, int f) {
        int first = 0, second = 0;
        for (auto& v : g[u]) {
            if (v == f) {
                continue;
            }
            depth[v] = depth[u] + 1;
            int x = dfs(v, u) + 1;
            if (x > second) {
                second = x;
                if (second > first) {
                    swap(second, first);
                }
            }
        }
        F[depth[u] + second] = max(F[depth[u] + second], first + second);
        return first;
    };

    int cur = 0, mx = dfs(0, -1);
    for (int i = mx - 1; i > 0; --i) {
        F[i] = max(F[i], F[i + 1]);
    }

    for (int i = 1; i <= (int)g.size(); ++i) {
        while (cur < mx &&
               (F[cur + 1] + 1) / 2 + i > cur)
               ++cur;
        cout << cur << ' ';
    }
    cout << nl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

