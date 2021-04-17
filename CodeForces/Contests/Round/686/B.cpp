
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<int> c(n+1),ai(n+1);
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            ++c[a];
            ai[a] = i + 1;
        }
        int res = -1;
        for (int i = 0; i < n + 1; ++i) {
            if (c[i] == 1) {
                res = ai[i];
                break;
            }
        }
        cout << res << '\n';
    }

    return 0;
}

