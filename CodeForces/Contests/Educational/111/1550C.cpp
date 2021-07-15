
/*
    author: MrS4g0
    created: 15.07.2021 16:32:18
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


int a[(int)2e5];

inline bool good3(int i, int j, int k) {
    return !((i <= j && j <= k) || (i >= j && j >= k));
}

void solve() {
    int n = nxt();
    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }

    int ans = n + n - 1;
    for (int i = 0; i + 2 < n; ++i) {
        if (good3(a[i], a[i + 1], a[i + 2])) {
            ++ans;
        }
    }
    for (int i = 0; i + 3 < n; ++i) {
        if (good3(a[i], a[i + 1], a[i + 2]) &&
            good3(a[i], a[i + 1], a[i + 3]) &&
            good3(a[i], a[i + 2], a[i + 3]) &&
            good3(a[i + 1], a[i + 2], a[i + 3])) {
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

