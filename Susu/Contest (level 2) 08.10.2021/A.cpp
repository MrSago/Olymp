
/*
    author: MrS4g0
    created: 08.10.2021 21:40:37
*/

#include <iostream>
using namespace std;

#define nl ('\n')

using ui64 = unsigned long long;
using ui128 = unsigned __int128;

inline ui128 uiget() { ui64 x; cin >> x; return (ui128)x; }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ui128 A = uiget(),
          K = uiget(),
          B = uiget(),
          M = uiget(),
          X = uiget();


    ui128 l = 0, r = X * max(A, B);

    while (l + 1 < r) {
        ui128 m = (l + r) >> 1;
        if (A * (m - m / K) + B * (m - m / M) >= X) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << (ui64)r << nl;

    return 0;
}

