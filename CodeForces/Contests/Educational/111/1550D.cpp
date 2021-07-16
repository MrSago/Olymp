
/*
    author: MrS4g0
    created: 16.07.2021 13:01:32
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


constexpr int MAXN = (int)2e5 + 1;
int fact[MAXN], inf[MAXN];

inline int norm(int a) {
    while (a >= MOD) {
        a -= MOD;
    }
    while (a < 0) {
        a += MOD;
    }
    return a;
}

inline int mul(int a, int b) {
    return (int)(a * 1ll * b % MOD);
}

inline int C(int n, int k) {
    if (k < 0 || n < k) {
        return 0;
    }
    return mul(fact[n], mul(inf[n - k], inf[k]));
}

inline int bpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

void calcfact() {
    fact[0] = inf[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = mul(fact[i - 1], i);
        inf[i] = bpow(fact[i], MOD - 2);
    }
}

void solve() {
    int n, l, r; cin >> n >> l >> r;

    int half = n / 2;
    int st = min(1 - l, r - n);
    int ans = mul(st, C(n, half));
    if (n & 1) {
        ans = norm(ans + mul(st, C(n, half + 1)));
    }
    for (int i = st + 1; ; ++i) {
        int lf = max(1, l + i);
        int rg = min(n, r - i);
        if (rg + 1 - lf < 0) {
            break;
        }
        ans = norm(ans + C(rg + 1 - lf, half - (lf - 1)));
        if (n & 1) {
            ans = norm(ans + C(rg + 1 - lf, half + 1 - (lf - 1)));
        }
    }
    
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    calcfact();
    for (int t = 1, tc = nxt(); t <= tc; ++t) {
        solve();
    }

    return 0;
}

