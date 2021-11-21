
/*
    author: MrS4g0
    created: 21.11.2021 13:19:36
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

struct Node {
    vector<int> child;
    int prev = -1;
    int value = 1;
    int s = 0;
};

vector<Node> g;

void update(int v) {
    int l = g[v].child[0];
    int r = g[v].child[1];
    int lv = g[l].value + g[l].s;
    int rv = g[r].value + g[r].s;
    int nv = __gcd(lv, rv);
    g[v].value = nv % MOD;
    g[v].s = (g[v].s + (nv / MOD)) % MOD;

    if (g[v].prev == -1) {
        return;
    }

    update(g[v].prev);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    g.resize(n + 1);
    for (int i = 2; i < n + 1; ++i) {
        int v = nxt();
        g[i].prev = v;
        g[v].child.push_back(i);
    }

    while (q--) {
        int v, x;
        i64 nv;
        switch (nxt()) {
            case 1:
                v = nxt();
                x = nxt();
                nv = g[v].value * 1ll * x;
                g[v].value = (int)(nv % MOD);
                g[v].s = (int)((g[v].s + (nv / MOD)) % MOD);
                update(g[v].prev);
            break;

            case 2:
                v = nxt();
                cout << g[v].value << nl;
            break;
        }
    }

    return 0;
}

