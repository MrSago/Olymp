
/*
    author: MrS4g0
    created: 01.08.2021 17:57:20
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


void solve() {
    int n = nxt();
    string s1, s2; cin >> s1 >> s2;
    int ans = 0;
    if (s2[0] == '1') {
        if (s1[0] == '0') {
            ++ans;
        } else {
            if (s1[1] == '1') {
                ++ans;
                s1[1] = '2';
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        if (s2[i] == '0') {
            continue;
        }
        if (s1[i] == '0') {
            ++ans;
        } else {
            if (s1[i - 1] == '1') {
                ++ans;
            } else if (s1[i + 1] == '1') {
                ++ans;
                s1[i + 1] = '2';
            }
        }
    }
    cout << ans << nl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

