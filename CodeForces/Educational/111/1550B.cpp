
/*
    author: MrS4g0
    created: 14.07.2021 18:07:03
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

template<typename T = int>
inline T nxt() { T x; cin >> x; return x; }


void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    int counts[2] = { 0 };
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            counts[s[i] - '0'] += 1;
        }
    }
    int ans = max(b * n, b * (min(counts[0], counts[1]) + 1));
    ans += a * n;
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

