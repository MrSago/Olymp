/*
    author: MrS4g0
    created: 12.09.2021 19:26:55
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


graph g;
vb used;
vc color;
int res = 0;
int N;

void dfs (int v) {
    color[v] = 1;
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to] && color[to] == 0) {
            ++res;
            dfs(to);
        }
        else if (color[to] == 1) {
            cout << "-1";
            exit(0);
        }
    }
    color[v] = 2;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = nxt();
    g.resize(51);
    used.assign(51, false);
    color.assign(51, 0);

    while (1) {
        int u = nxt(), v = nxt();
        if (u == 0 && v == 0) {
            break;
        }
        g[u].push_back(v);
    }

    dfs(N);
    cout << res << nl;

    return 0;
}

