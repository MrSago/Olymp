
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t n; cin >> n;
    int64_t res = 0, zc = 0, nc = 0;
    while (n--) {
        int64_t a; cin >> a;
        res += a > 0 ? a - 1 : a < 0 ? -a - 1 : 0 & ++zc;
        nc += a < 0;
    }

    res = zc ? res + zc : nc % 2 ? res + 2 : res;
    cout << res << '\n';

    return 0;
}

