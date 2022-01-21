
/*
    author: MrS4g0
    created: 11.09.2021 23:42:16
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


int N, M;
graph g;
vb used;

int circles = 0, lines = 0;
bool f_circle;
int start;

void dfs(int v, int p = -1) {
    used[v] = true;
    for (auto& u : g[v]) {
        if (!used[u]) {
            dfs(u, v);
        } else if (u == start && u != p && !f_circle) {
            start = -1;
            f_circle = true;
            ++circles;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d%d", &N, &M);
    getchar();

    g.resize(N * M);
    used.assign(g.size(), false);

    vb image(g.size(), false);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (getchar() == '1') {
                image[j + i * M] = true;
            }
        }
        getchar();
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int cur = j + i * M;
            if (image[cur]) {
                bool left_up = false;
                bool left_down = false;
                bool right_up = false;
                bool right_down = false;

                // Left
                if (j > 0 && image[(j - 1) + i * M]) {
                    g[cur].push_back((j - 1) + i * M);
                    left_up = true;
                    left_down = true;
                }
                // Right
                if (j < M - 1 && image[(j + 1) + i * M]) {
                    g[cur].push_back((j + 1) + i * M);
                    right_up = true;
                    right_down = true;
                }
                // Up
                if (i > 0 && image[j + (i - 1) * M]) {
                    g[cur].push_back(j + (i - 1) * M);
                    left_up = true;
                    right_up = true;
                }
                // Down
                if (i < M - 1 && image[j + (i + 1) * M]) {
                    g[cur].push_back(j + (i + 1) * M);
                    left_down = true;
                    right_down = true;
                }
                // Left-Up
                if (!left_up && j > 0 && i > 0 && image[(j - 1) + (i - 1) * M]) {
                    g[cur].push_back((j - 1) + (i - 1) * M);
                }
                // Right-Up
                if (!right_up && j < M - 1 && i > 0 && image[(j + 1) + (i - 1) * M]) {
                    g[cur].push_back((j + 1) + (i - 1) * M);
                }
                // Down-Left
                if (!left_down && j > 0 && i < M - 1 && image[(j - 1) + (i + 1) * M]) {
                    g[cur].push_back((j - 1) + (i + 1) * M);
                }
                // Down-Right
                if (!right_down && j < M - 1 && i < M - 1 && image[(j + 1) + (i + 1) * M]) {
                    g[cur].push_back((j + 1) + (i + 1) * M);
                }
            }
        }
    }

    for (int i = 0; i < (int)g.size(); ++i) {
        if (g[i].size() && !used[i]) {
            f_circle = false;
            start = i;
            dfs(i);
            lines += !f_circle;
        }
    }

    cout << circles << ' ' << lines << '\n';

    return 0;
}

