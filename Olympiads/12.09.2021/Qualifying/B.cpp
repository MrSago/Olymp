
/*
    author: MrS4g0
    created: 20.09.2021 19:32:59
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

    char s[5002];
    while (fgets(s, 5002, stdin)) {
        int s_len = (int)strlen(s) - 1;
        bool f = false;
        if (s[0] == '1') {
            cout << "10";
            f = true;
        } else if (s[0] > '1') {
            cout << '1' << s[0];
            f = true;
        }
        for (int i = (int)f; i < s_len; ++i) {
            cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}

