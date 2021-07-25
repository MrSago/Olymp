
/*
    author: MrS4g0
    created: 25.07.2021 17:36:00
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
    int n = nxt();
    string s; cin >> s;
    string a = s;
    int ans = 0;
    sort(s.begin(), s.end());
    for (int i = 0; i < n; ++i) {
        if (s[i] != a[i]) {
            ++ans;
        }
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

