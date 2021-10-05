
/*
    author: MrS4g0
    created: 24.07.2021 15:53:55
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
    int n = nxt(), k = nxt();
    int cnt = 0;
    map<int,vi> pos;
    for (int i = 0; i < n; ++i) {
        int x = nxt();
        if ((int)pos[x].size() < k) {
            pos[x].push_back(i);
            ++cnt;
        }
    }

    vi ans(n);
    cnt = (cnt - cnt % k) / k;
    for (int i = 0; i < cnt; ++i) {
        int color = 0;
        while (color < k) {
            auto it = pos.begin();
            if (it->second.empty()) {
                pos.erase(it);
                continue;
            }
            ans[it->second.back()] = ++color;
            it->second.pop_back();
        }
    }

    for (auto& it : ans) {
        cout << it << ' ';
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

