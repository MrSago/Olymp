
#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using LD = long double;

using vi = vector<int>;
using vll = vector<LL>;
using vull = vector<ULL>;
using vb = vector<bool>;

using Graph = vector<vi>;

inline int nxt() { int x; scanf("%d", &x); return x; }
inline LL nxtLL() { LL x; scanf("%lld", &x); return x; }
inline ULL nxtULL() { ULL x; scanf("%llu", &x); return x; }

constexpr int MOD = 1000007;


void solve(int test = 1) {
    Graph g(nxt());
    vi color(g.size(), 0);
    vb gray(g.size(), false);
    vb black(g.size(), false);

    for (int m = nxt(); m > 0; --m) {
        g[nxt() - 1].push_back(nxt() - 1);
    }

    function<void(int)> dfs = [&](int v) {
        color[v] = 1;
        for (int& u : g[v]) {
            if (color[u] == 1) {
                gray[u] = true;
            } else if (color[u] == 2) {
                black[u] = true;
            } else {
                dfs(u);
            }
        }
        color[v] = 2;
    };

    dfs(0);

    function<void(int)> dfs2 = [&](int v) {
        for (int& u : g[v]) {
            if (!gray[u]) {
                gray[u] = true;
                dfs2(u);
            }
        }
    };

    function<void(int)> dfs3 = [&](int v) {
        for (int& u : g[v]) {
            if (!black[u]) {
                black[u] = true;
                dfs3(u);
            }
        }
    };

    for (int i = 0; i < (int)g.size(); ++i) {
        if (gray[i]) {
            dfs2(i);
        }
        if (black[i]) {
            dfs3(i);
        }
    }

    for (int i = 0; i < (int)g.size(); ++i) {
        if (!color[i]) {
            cout << "0 ";
        } else if (gray[i]) {
            cout << "-1 ";
        } else if (black[i]) {
            cout << "2 ";
        } else {
            cout << "1 ";
        }
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve(t);
    }

    return 0;
}

