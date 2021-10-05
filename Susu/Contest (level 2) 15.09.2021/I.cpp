
/*
    author: MrS4g0
    created: 16.09.2021 23:11:57
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

constexpr int MOD = int(1e9) + 7;
constexpr int NMOD = 998244353;


struct npi{
    int n, p, i;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vi nums[4];
    for (int i = 0; i < 4; ++i) {
        int N = nxt();
        for (int j = 0; j < N; ++j) {
            nums[i].push_back(nxt());
        }
        sort(nums[i].begin(), nums[i].end());
    }

    int pos[4] = { 0 };
    int ans[4];
    int mmin = INT_MAX;
    bool flag = true;

    while (flag) {
        flag = false;

        npi p[4];
        for (int i = 0; i < 4; ++i) {
            p[i] = { nums[i][pos[i]], pos[i], i };
        }
        sort(p, p + 4,
            [](npi& a, npi& b) {
                return a.n < b.n;
            }
        );

        int dif = p[3].n - p[0].n;
        if (dif < mmin) {
            mmin = dif;
            for (int i = 0; i < 4; ++i) {
                ans[p[i].i] = p[i].n;
            }
        }

        for (int i = 0; i < 4; ++i) {
            if (p[i].p != (int)nums[p[i].i].size() - 1) {
                ++pos[p[i].i];
                flag = true;
                break;
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}

