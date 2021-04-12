
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        uint64_t sum = 0;
        while (n--) {
            uint64_t a; cin >> a;
            if (a <= 2048) {
                sum += a;
            }
        }
        if (sum >= 2048) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

