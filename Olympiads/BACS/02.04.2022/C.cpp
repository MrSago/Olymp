
/*
    author: MrS4g0
    created: 02.04.2022 10:42:22
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using i64 = long long;
using ui64 = unsigned long long;
using ld = long double;

using i128 = __int128;
using ui128 = unsigned __int128;
inline i128 iget() { i64 x; cin >> x; return static_cast<i128>(x); }
inline ui128 uiget() { ui64 x; cin >> x; return static_cast<ui128>(x); }

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


struct node {
    int v = -1;
    int last = -1;
};

constexpr int MAXN = int(2e5+5);
string v[MAXN];
node g[MAXN];
bool used[MAXN] = { false };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = nxt();
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
    
        if (g[b].v == -1) {
            g[b].v = a;
        } else {
            g[g[b].last].v = a;
        }
        g[b].last = g[a].last == -1 ? a : g[a].last;

        used[a] = true;
    }

    int cur = -1;
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            cur = i;
            break;
        }
    }

    cout << v[cur];
    while (g[cur].v != -1) {
        cout << v[g[cur].v];
        cur = g[cur].v;
    }
    cout << nl;

    return 0;
}

