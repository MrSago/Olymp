
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int x; cin >> x;
        int cur = 0;
        int i = 1;
        do {
            cur = (i * (i + 1)) / 2;
            ++i;
        } while (cur < x);

        if (x == cur - 1) {
            cout << i << '\n';
        }
        else {
            cout << i - 1 << '\n';
        }
    }
    return 0;
}

