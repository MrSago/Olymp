
/*
    author: MrS4g0
    created: 31.10.2021 14:36:02
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using ui64 = unsigned long long;

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }

pair<int,bool> v[int(1e5)];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = nxt() << 1, i = 0;
    while (i < N) {
        int f = nxt();
        v[i++] = { f, true };
        v[i++] = { f + nxt(), false };
    }

    sort(v, v + N);

    int cnt = 0, tmp = 0;
    for (i = 0; i < N; ++i) {
        tmp += v[i].second ? 1 : -1;
        cnt = max(cnt, tmp);
    }
    cout << cnt << nl;

    return 0;
}

