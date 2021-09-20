
/*
    author: MrS4g0
    created: 20.09.2021 20:05:16
*/

#include <iostream>
using namespace std;

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    printf("%.6lf\n", max(0.0, (6.0 - (nxt<double>() + nxt<double>())) / 6.0));

    return 0;
}

