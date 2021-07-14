
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int kk = k;
        for (int i = 0; kk > 0 && i < n - 1; ++i) {
            kk -= a[i];
            if (kk < 0) {
                a[i] = -kk;
                kk = 0;
                break;
            } else {
                a[i] = 0;
            }
        }
        a[n - 1] += k - kk;

        for (const auto& it : a) {
            cout << it << ' ';
        }
        cout << '\n';
    }

    return 0;
}

