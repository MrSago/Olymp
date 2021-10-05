
#include <iostream>

using namespace std;

template<typename T = int>
inline T nxt() {
    T x; cin >> x; return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = nxt();
    while (tt--) {
        int n = nxt();
        uint64_t sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nxt();
        }
        int ost = sum % n;
        cout << 1ll * ost * (n - ost) << '\n';
    }

    return 0;
}

