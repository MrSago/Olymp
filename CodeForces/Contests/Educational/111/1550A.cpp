
/*
    author: MrS4g0
    created: 14.07.2021 17:35:42
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

inline int nxt() { int x; scanf("%d", &x); return x; }
inline LL nxtLL() { LL x; scanf("%lld", &x); return x; }
inline ULL nxtULL() { ULL x; scanf("%llu", &x); return x; }

constexpr int MOD = 1000007;


void solve(int test = 1) {
    int s = nxt();
    int d = 1;
    int ans = 1;
    while (s - d > 0) {
        ++ans;
        s -= d;
        d += 2;
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve(t);
    }

    return 0;
}

