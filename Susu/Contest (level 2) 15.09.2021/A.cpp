
/*
    author: MrS4g0
    created: 16.09.2021 13:27:11
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vi indexes[26];
    for (int i = 0, c; (c = getchar()) != '\n'; ++i) {
        indexes[c - 'a'].push_back(i);
    }

    set<char> sym;
    int counts[26];
    memset(counts, 0, sizeof(int) * 26);
    for (int c; (c = getchar()) != '\n'; ) {
        ++counts[c - 'a'];
        sym.insert((char)c);
    }

    int d = INT_MAX, f = -1;

    for (auto& it : sym) {
        int ix = (int)(it - 'a');
        int count = counts[ix];
        if ((int)indexes[ix].size() < count) {
            d = f = -1;
            break;
        } else if ((int)indexes[ix].size() == count) {
            d = 0;
            f = indexes[ix][0];
            break;
        }
        auto l = indexes[ix].begin();
        auto r = indexes[ix].end() - 1 - (count - 1);
        for ( ; r != indexes[ix].end(); ++l, ++r) {
            int dif = *r - *l;
            if (dif < d) {
                d = dif;
                f = *l;
            }
        }
    }

    cout << d + 1 << ' ' << f + 1 << '\n';

    return 0;
}

