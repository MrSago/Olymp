
/*
    author: MrS4g0
    created: 12.09.2021 20:36:34
*/

#include <iostream>
using namespace std;

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = nxt();
    int K = nxt();
    int R = 0;

    if (T + K > 8 && T < 9) {
        ++R;
    }
    if (T + K + R > 13 && T < 14) {
        ++R;
    }
    if (T + K + R > 18) {
        ++R;
    }

    cout << T + K + R << '\n';

    return 0;
}

