
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

pair<int,bool> v[30000];
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = nxt() << 1;
    for (int i = 0; i < N;) {
        v[i++] = { nxt(), false };
        v[i++] = { nxt(), true };
    }

    sort(v, v + N);

    ui64 sum = 0;
    for (int i = 0; i < N; ++i) {
        if (!v[i].second) {
            s.push(v[i].first);
        } else {
            if (s.size() > 1) {
                s.pop();
            } else {
                sum += v[i].first - s.top();
                s.pop();
            }
        }
    }
    cout << sum << nl;

    return 0;
}

