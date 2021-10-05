
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool ok = false;
        while (n--) {
            int a; cin >> a;
            if (!ok) {
                double sq = sqrt(a);
                if (sq != (int)sq) {
                    ok = true;
                }
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

