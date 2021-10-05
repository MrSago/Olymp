
/*
    author: MrS4g0
    created: 22.07.2021 18:53:12
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
    string s; cin >> s;
    int ans = 9;
    for (int i = 0, c0 = 0, c1 = 0; i < 10; ++i) {
        if (i % 2) {
            c1 += s[i] == '1';
        } else {
            c0 += s[i] != '0';
        }
        if (c0 - c1 > (10 - i) / 2) {
            ans = min(ans, i);
        }
        if (c1 - c0 > (9 - i) / 2) {
            ans = min(ans, i);
        }
    }
    for (int i = 0, c0 = 0, c1 = 0; i < 10; ++i) {
        if (i % 2) {
            c1 += s[i] != '0';
        } else {
            c0 += s[i] == '1';
        }
        if (c0 - c1 > (10 - i) / 2) {
            ans = min(ans, i);
        }
        if (c1 - c0 > (9 - i) / 2) {
            ans = min(ans, i);
        }
    }

    cout << ans + 1 << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

