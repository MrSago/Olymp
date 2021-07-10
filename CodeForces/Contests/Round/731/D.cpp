
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
        int x[(int)2e5];
        int n = nxt();
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }

        int last = 0;
        cout << 0;
        for (int i = 1; i < n; ++i) {
            cout << ' ' << (last = (last ^ x[i - 1]) & ~x[i]);
        }
        cout << '\n';
    }

    return 0;
}

