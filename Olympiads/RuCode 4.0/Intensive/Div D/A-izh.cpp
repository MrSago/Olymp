
/*
    author: MrS4g0
    created: 15.11.2021 15:32:23
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
constexpr int INF = int(1e9);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int,pi>> g(m);
    for (int i = 0; i < m; ++i) {
        g[i].second = { nxt(), nxt() };
        g[i].first = nxt();
    }

    sort(g.begin(), g.end());

    vi tree_id(n);
    iota(tree_id.begin(), tree_id.end(), 0);

    size_t ans = 0;
    for (int i = 0; i < m; ++i) {
        int a = g[i].second.first;
        int b = g[i].second.second;
        int w = g[i].first;
        if (tree_id[a] != tree_id[b]) {
            ans += (size_t)w;
            int old_id = tree_id[b];
            int new_id = tree_id[a];
            for (int j = 0; j < n; ++j) {
                if (tree_id[j] == old_id) {
                    tree_id[j] = new_id;
                }
            }
        }
    }

    cout << ans << nl;

    return 0;
}

