
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
        int k, n, m; cin >> k >> n >> m;
        int a[100], b[100], res[200];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        bool ok = true;
        int i = 0, j = 0, s = 0;
        while (i < n || j < m) {
            if (i < n) {
                if (a[i] == 0) {
                    res[s++] = 0;
                    ++k; ++i;
                    continue;
                }
                if (a[i] <= k) {
                    res[s++] = a[i++];
                    continue;
                }
            }
            if (j < m) {
                if (b[j] == 0) {
                    res[s++] = 0;
                    ++k; ++j;
                    continue;
                }
                if (b[j] <= k) {
                    res[s++] = b[j++];
                    continue;
                }
            }
            ok = false;
            break;
        }

        if (ok) {
            for (int i = 0; i < s; ++i) {
                cout << res[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}

