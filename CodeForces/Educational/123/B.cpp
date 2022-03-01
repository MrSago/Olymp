
/*
    author: MrS4g0
    created: 22.02.2022 17:42:38
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using i64 = long long;
using ui64 = unsigned long long;
using ld = long double;

using i128 = __int128;
using ui128 = unsigned __int128;
inline i128 iget() { i64 x; cin >> x; return static_cast<i128>(x); }
inline ui128 uiget() { ui64 x; cin >> x; return static_cast<ui128>(x); }

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


bool check(vi& v) {
    for (int i = 0; i < (int)v.size() - 2; ++i) {
        if (v[i] + v[i + 1] == v[i + 2]) {
            return false;
        }
    }
    return true;
}

void print(vector<int>& v) {
    for (auto& it : v) {
        cout << it << ' ';
    }
    cout << nl;
}


void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int z = 0; z <= n; ++z) {
        for (int i = n; i > 0; --i) {
            vector<int> v;

            for (int j = n; j > i; --j) {
                if (j == z) {
                    v.push_back(i);
                }
                v.push_back(j);
            }

            for (int j = i - 1; j > 0; --j) {
                if (j == z) {
                    v.push_back(i);
                }
                v.push_back(j);
            }

            if (v.size() < n) {
                v.push_back(i);
            }
            bool flag = true;

            for (int j = 2; j < v.size(); ++j) {
                if (v[j-2] + v[j-1] == v[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                print(v);
                if (++cnt == n) {
                    return;
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

