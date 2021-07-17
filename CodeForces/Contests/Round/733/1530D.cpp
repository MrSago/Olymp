
/*
    author: MrS4g0
    created: 17.07.2021 18:45:18
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

Graph g;
vi colors;
vb entered;

int search_ent() {
    for (int i = 1; i < (int)entered.size(); ++i) {
        if (!entered[i]) {
            entered[i] = true;
            return i;
        }
    }
    return -1;
}

void dfs(int v) {
    colors[v] = 1;
    for (int& u : g[v]) {
        entered[u] = true;
        if (colors[u] == 1) {
            g[v].clear();
            g[v].push_back(search_ent());
        } else if (colors[u] == 0) {
            dfs(u);
        }
    }
    colors[v] = 2;
}

void solve() {
    int n = nxt();
    g.resize(n + 1);
    colors.assign(n + 1, 0);
    entered.assign(n + 1, false);
    for (int i = 1; i < (int)g.size(); ++i) {
        g[i].push_back(nxt());
    }

    for (int i = 1; i < n; ++i) {
        dfs(i);
    }

    cout << n << '\n';
    for (int i = 1; i < n; ++i) {
        cout << g[i][0] << ' ';
    }
    cout << '\n';

    g.clear();
    colors.clear();
    entered.clear();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

