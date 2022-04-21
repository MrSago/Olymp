
/*
    author: MrS4g0
    created: 09.03.2022 08:33:54
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

constexpr int MOD = int(1e9) + 7;
constexpr int NMOD = 998244353;

constexpr int INF = int(1e8);
constexpr double EPS = 1e-8;

int N, K, A, B;
graph g;

vi dst_a, dst_b;
vb used;

void dejkstra(int start, vi& dst) {
    fill(used.begin(), used.end(), false);
    fill(dst.begin(), dst.end(), INF);

    dst[start] = 0;

    while (true) {
        int mn = INF, v = -1;
        for (int i = 0; i < N; ++i) {
            if (!used[i] && dst[i] < mn) {
                mn = dst[i];
                v = i;
            }
        }

        if (mn >= INF) {
            break;
        }

        used[v] = true;

        for (int i = 0; i < N; ++i) {
            dst[i] = min(dst[i], dst[v] + g[v][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> A >> B;
    --A, --B;

    g.resize(N);
    fill(g.begin(), g.end(), vi(N, INF));

    used.resize(N);
    dst_a.resize(N);
    dst_b.resize(N);

    for (int i = 0; i < K; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u][v] = g[v][u] = w;
    }

    dejkstra(A, dst_a);
    dejkstra(B, dst_b);

    vi ans;
    double mn = 1e100;

    for (int i = 0; i < N; ++i) {
        if (i == A || i == B) {
            continue;
        }

        double a =  dst_a[i] != INF ? 1.0 / dst_a[i] : 0.0;
        double b =  dst_b[i] != INF ? 1.0 / dst_b[i] : 0.0;
        double sum = a + b;

        if (sum < mn - EPS) {
            mn = sum;
            ans.clear();
            ans.push_back(i);
        } else if (fabs(sum - mn) <= EPS) {
            ans.push_back(i);
        }
    }

    for (auto& it : ans) {
        cout << it + 1 << nl;
    }

    return 0;
}

