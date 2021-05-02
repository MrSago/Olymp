
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        int a[100];
        int res = 0, index = -1;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            res += a[i];
            if (res == x) {
                index = i;
            }
        }

        if (res == x) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (i == index) {
                cout << a[--n] << ' ';
            }
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

