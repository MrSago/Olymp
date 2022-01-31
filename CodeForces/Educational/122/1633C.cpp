
/*
    author: MrS4g0
    created: 31.01.2022 18:08:05
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using i64 = long long;
using ui64 = unsigned long long;
using ld = long double;

// using i128 = __int128;
// using ui128 = unsigned __int128;
// inline i128 iget() { i64 x; cin >> x; return (i128)x; }
// inline ui128 uiget() { ui64 x; cin >> x; return (ui128)x; }

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vi64 = vector<i64>;
using vui64 = vector<ui64>;

using pi = pair<int,int>;
using pi64 = pair<i64,i64>;
using pui64 = pair<ui64,ui64>;
using graph = vector<vi>;

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }

constexpr int MOD = int(1e9) + 7;
constexpr int NMOD = 998244353;




bool win(ui64 hc, ui64 dc, ui64 hm, ui64 dm) {
    ui64 steps_to_kill_m = hm / dc + (hm % dc > 0);
    ui64 steps_to_kill_c = hc / dm + (hc % dm > 0);
    return steps_to_kill_m <= steps_to_kill_c;
}


void solve() {
    ui64 hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;

    for (int i = k; i >= 0; --i) {
        ui64 dmg = i * w;
        ui64 hp = (k - i) * a;
        if (win(hc + hp, dc + dmg, hm, dm)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

