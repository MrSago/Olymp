
/*
    author: MrS4g0
    created: 24.07.2021 15:13:57
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
    int ans = 0;
    bool last = false;

    for (char c = 'a'; c <= 'z'; ++c) {
        int cnt = (int)count(s.begin(), s.end(), c);
        if (cnt >= 2) {
            ++ans;
        } else if (cnt == 1) {
            if (last) {
                ++ans;
                last = false;
            } else {
                last = true;
            }
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

