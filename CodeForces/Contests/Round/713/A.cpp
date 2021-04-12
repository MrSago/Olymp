
#include <iostream>
#include <algorithm>

using namespace std;

int v[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int f, f_i, s, s_i;
        cin >> v[0];
        f = v[0]; f_i = 0;
        for (int i = 1; i < n; ++i) {
            cin >> v[i];
            if (v[i] != f) {
                s = v[i]; s_i = i;
            }
        }
        if (count(v, v + n, f) == 1) {
            cout << f_i + 1 << '\n';
        } else {
            cout << s_i + 1 << '\n';
        }
    }

    return 0;
}

