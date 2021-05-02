
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        uint64_t sum = 1;
        uint64_t i = 0;
        bool ok = false;

        while (sum <= n) {
            if (sum * 2 == n || sum * 4 == n) {
                ok = true;
                break;
            }
            ++i;
            sum = i * i;
        }

        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

