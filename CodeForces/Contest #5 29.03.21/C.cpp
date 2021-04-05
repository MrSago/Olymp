
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    if (k == 1 || l == 1 || m == 1 || n == 1) {
        cout << d << '\n';
        return 0;
    }
    if (k > d && l > d && m > d && n > d) {
        cout << "0\n";
        return 0;
    }

    int res = 0;
    for (int i = 1; i <= d; ++i) {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
            ++res;
        }
    }

    cout << res << '\n';

    return 0;
}

