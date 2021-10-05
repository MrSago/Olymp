
/*
    author: MrS4g0
    created: 25.07.2021 17:40:21
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
    vector<vi> arr(n, vi(5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> arr[i][j];
        }
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < 5; ++j) {
            count += arr[i][j] < arr[ans][j];
        }
        if (count >= 3) {
            ans = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < 5; ++j) {
            count += arr[i][j] < arr[ans][j];
        }
        if (count >= 3) {
            cout << "-1\n";
            return;
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

