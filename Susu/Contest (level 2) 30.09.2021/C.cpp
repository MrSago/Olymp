
/*
    author: MrS4g0
    created: 06.10.2021 16:09:24
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pii> v(nxt());
    for (auto& it : v){
        it.first = nxt();
        it.second = nxt();
    }

    sort(v.begin(), v.end(),
         [&](auto& a, auto& b) {
             return a.second > b.second;
         }
    );

    vb vis(v.size(), true);

    int ans = (int)v.size();
    for (int i = 0; i < (int)v.size() - 1; ++i) {
        if (!vis[i]) {
            continue;
        }
        int x0 = v[i].first, h = v[i].second;
        for (int j = i + 1; j < (int)v.size(); ++j) {
            if (!vis[j]) {
                continue;
            }
            int x = v[j].first, y = v[j].second;
            if (y <= x - (x0 - h) && y <= -x + (x0 + h)) {
                --ans;
                vis[j] = false;
            }
        }
    }

    cout << ans << nl;

    return 0;
}

