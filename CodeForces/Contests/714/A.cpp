
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (k > (n - 1) / 2) {
            cout << "-1\n";
            continue;
        }

        cout << "1 ";
        int min = 2, max = n, count = 0;
        while (k--) {
            cout << max-- << ' ' << min++ << ' ';
            count += 2;
        }
        while (++count != n) {
            cout << min++ << ' ';
        }
        cout << '\n';
    }

    return 0;
}

