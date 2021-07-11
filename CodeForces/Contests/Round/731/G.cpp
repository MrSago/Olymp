
#include <iostream>
#include <vector>

using namespace std;

using LL = long long int;
using ULL = unsigned long long int;

template<typename T = int>
inline T nxt() {
    T x; cin >> x; return x;
}

vector<vector<int>> g;
vector<int> color;
vector<bool> gray, black;

void dfs(int v) {
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
}

void dfs2(int v) {
    for (int& u : g[v]) {
        if (!gray[u]) {
            gray[u] = true;
            dfs2(u);
        }
    }
}

void dfs3(int v) {
    for (int& u : g[v]) {
        if (!black[u]) {
            black[u] = true;
            dfs3(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = nxt();
    while (tt--) {
        g.resize(nxt());
        for (int i = 0, m = nxt(); i < m; ++i) {
            g[nxt() - 1].push_back(nxt() - 1);
        }

        color.assign(g.size(), 0);
        gray.assign(g.size(), false);
        black.assign(g.size(), false);
        dfs(0);
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

        g.clear();
        color.clear();
        gray.clear();
        black.clear();
    }

    return 0;
}

