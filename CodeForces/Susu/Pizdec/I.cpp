
/*
    author: MrS4g0
    created: 11.09.2021 22:24:48
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

template<typename T = int>
inline T nxt() { T x; cin >> x; return x; }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int S = nxt() << 1;
    int n = (int)sqrt(S);
    for ( ; n > 1; --n) {
        if (S % n == 0 && (S / n - n + 1) % 2 == 0) {
            break;
        }
    }

    cout << n << nl;

    return 0;
}

