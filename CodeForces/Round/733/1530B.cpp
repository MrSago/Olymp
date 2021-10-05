
/*
    author: MrS4g0
    created: 17.07.2021 17:40:02
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


void solve() {
    int x = nxt(), y = nxt();
    bool t[20][20];
    memset(t, 0, 20 * 20);

    if (x > y) {
        for (int i = 0; i < x; i += 2) {
            t[i][0] = true;
            t[i][y - 1] = true;
        }
        for (int i = 2; i < y - 2; i += 2) {
            t[0][i] = true;
            t[x - 1][i] = true;
        }
    } else {
        for (int i = 0; i < y; i += 2) {
            t[0][i] = true;
            t[x - 1][i] = true;
        }
        for (int i = 2; i < x - 2; i += 2) {
            t[i][0] = true;
            t[i][y - 1] = true;
        }
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cout << t[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

