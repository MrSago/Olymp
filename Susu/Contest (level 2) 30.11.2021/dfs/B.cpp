
/*
    author: MrS4g0
    created: 01.12.2021 15:08:24
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


constexpr int MAXN = 100005;
ui64 p[MAXN], s[MAXN], d[2 * MAXN], f[MAXN + 1], u[MAXN];
int m;

void dfs(ui64 v) {
    if (u[v]) {
        return;
    }
    for (ui64 i = f[v]; i <= f[v + 1] - 1; ++i) {
        dfs(d[i]);
    }
    u[v] = true;
    ++m;
    s[m] = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = nxt();
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    m = 1;
    for (int i = 1; i <= n; ++i) {
        int k = nxt();
        f[i] = m;
        for (int j = 1; j <= k; ++j) {
            cin >> d[m++];
        }
    }
    f[n + 1] = m;

    m = 0;
    dfs(1);

    ui64 t = 0;
    for (int i = 1; i <= m; ++i) {
        t += p[s[i]];
    }

    cout << t << ' ' << m << nl;
    for (int i = 1; i <= m; ++i) {
        cout << s[i] << ' ';
    }
    cout << nl;

    return 0;
}

