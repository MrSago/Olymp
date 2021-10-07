
/*
    author: MrS4g0
    created: 07.10.2021 12:07:58
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

    queue<int> q;
    int n = nxt();
    int last = 0;

    for (int i = 0; i < n; ++i) {
        int c = nxt();
        if (c == last + 1) {
            ++last;
        } else {
            q.push(c);
        }
        while (!q.empty() && q.front() == last + 1) {
            q.pop();
            ++last;
        }
    }

    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (c == last + 1) {
            ++last;
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}

