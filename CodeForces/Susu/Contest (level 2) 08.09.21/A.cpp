
/*
    author: MrS4g0
    created: 11.09.2021 19:31:42
*/

#include <iostream>
#include <cmath>
using namespace std;


template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << (int)pow(2, nxt()) - 1 << '\n';

    return 0;
}

