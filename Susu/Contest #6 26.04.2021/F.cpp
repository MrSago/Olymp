
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            sum += a;
        }

        if (m < n || n == 2) {
            cout << "-1\n";
            continue;
        }

        cout << sum * 2 << '\n' << n << " 1\n";
        for (int i = 1; i < n; ++i) {
            cout << i << ' ' << i + 1 << '\n';
        }
    }

    return 0;
}

