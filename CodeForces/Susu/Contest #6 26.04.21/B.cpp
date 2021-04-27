
#include <iostream>
#include <vector>

using namespace std;

vector<int> g[2000];
int res = 1;

void dfs(int u, int d = 1) {
    res = max(res, d);
    for (int& v : g[u]) {
        dfs(v, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int p; cin >> p;
        if (p == -1) {
            continue;
        }
        g[i].push_back(p);
    }

    for (int i = 0; i < n; ++i) {
        dfs(i);
    }

    cout << res << '\n';

    return 0;
}

