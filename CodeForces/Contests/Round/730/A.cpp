
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
        uint64_t a, b; cin >> a >> b;
        if (a == b) {
            cout << "0 0 \n";
            continue;
        }
        uint64_t r = max(a, b) - min(a, b);
        cout << r << ' ' << min(a % r, r - a % r) << '\n';
    }

    return 0;
}

