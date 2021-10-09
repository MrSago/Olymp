
/*
    author: MrS4g0
    created: 08.10.2021 23:37:58
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

const int INF = 1000000000;

struct star_s {
    int x, y, z;
};

inline int dist(struct star_s a, struct star_s b) {
    int x = b.x - a.x,
        y = b.y - a.y,
        z = b.z - a.z;
    return x * x + y * y + z * z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = nxt() + 1;
    vector<star_s> s(n);

    s[0] = { 0, 0, 0 };
    for (int i = 1; i < (int)s.size(); ++i) {
        s[i] = { nxt(), nxt(), nxt() };
    }

    graph g(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            g[i][j] = dist(s[i], s[j]);
        }
    }

    int ans = 0;
    vb used(n);
    vi min_e (n, INF), sel_e (n, -1);
    min_e[0] = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (v == -1 || min_e[j] < min_e[v])) {
                v = j;
            }
        }
        if (min_e[v] == INF) {
            throw runtime_error("gg wp");
        }

        used[v] = true;
        if (sel_e[v] != -1) {
            ans = max(ans, g[v][sel_e[v]]);
        }

        for (int to = 0; to < n; ++to) {
            if (g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
        }
    }

    cout << ans << nl;

    return 0;
}

