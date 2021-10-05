
#include <iostream>
#include <vector>

using namespace std;

vector<short> g[2001];
short n;
int res = 1;

void dfs(short v, int d = 1) {
    res = max(res, d);
    for (short u : g[v]) {
        dfs(u, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (short i = 1; i <= n; ++i) {
        short p; cin >> p;
        if (p == -1) {
            continue;
        }
        g[p].push_back(i);
    }

    for (short i = 1; i <= n; ++i) {
        dfs(i);
    }

    cout << res << '\n';

    return 0;
}

