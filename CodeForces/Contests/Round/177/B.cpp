
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


void solve() {
    vi a(nxt() * nxt());
    int d = nxt();
    for (auto& it : a) {
        it = nxt();
    }
    for (int i = 1, m = a[0] % d; i < (int)a.size(); ++i) {
        if (a[i] % d != m) {
            cout << "-1\n";
            return;
        }
    }
    sort(a.begin(), a.end());
    int mid = a[a.size() / 2];
    int ans = 0;
    for (auto& it : a) {
        ans += abs(it - mid);
    }
    cout << ans / d << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

