
/*
    author: MrS4g0
    created: 11.09.2021 19:50:50
*/

#include <iostream>
using namespace std;

constexpr size_t S = 1000000000;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t x, k;
    cin >> x >> k;

    size_t cnt = 0;
    while (x < S) {
        x *= k;
        if (x < S) {
            ++cnt;
        }
    }

    cout << cnt << '\n';

    return 0;
}

