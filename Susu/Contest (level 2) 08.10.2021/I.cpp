
/*
    author: MrS4g0
    created: 10.10.2021 16:34:43
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<pi> sum(n + 1);
    sum[0] = { 0, 0 };

    int s = 0;
    for (int i = 1; i <= n; ++i) {
        s += nxt();
        sum[i] = { s, i };
    }
    sort(sum.begin(), sum.end());

    int start = 0, mxlen = 0, nlen;
    for (int i = 0; i <= n; ++i) {
        if (i > 0 && sum[i].first == sum[i - 1].first) {
            continue;
        }

        int next = upper_bound(sum.begin(), sum.end(),
                        make_pair(sum[i].first + k, n + 1)) - sum.begin();

        if (next > 0 && sum[next - 1].first == sum[i].first + k &&
            (nlen = sum[next - 1].second - sum[i].second) > 0) {
            if (mxlen < nlen) {
                mxlen = nlen;
                start = sum[i].second + 1;
            } else if (mxlen == nlen) {
                start = min(start, sum[i].second + 1);
            }
        }
    }

    cout << start << ' ' << mxlen << nl;

    return 0;
}

