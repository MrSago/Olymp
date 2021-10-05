
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> nV(n);
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            nV[i] = a;
        }
        int count = 0;
        for (int i = 0; i < m; ++i) {
            int a; cin >> a;
            for (auto j: nV) {
                if (a == j){
                    ++count;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}

