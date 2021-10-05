
#include <iostream>
#include <vector>

using namespace std;

using LL = long long int;
using ULL = unsigned long long int;

template<typename T = int>
inline T nxt() {
    T x; cin >> x; return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = nxt();
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> pos(k);
        for (int i = 0; i < k; ++i) {
            cin >> pos[i];
        }
        vector<LL> temp(n, INT_MAX);
        for (int i = 0; i < k; ++i) {
            cin >> temp[pos[i] - 1];
        }

        LL mint = INT_MAX;
        vector<LL> L(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            mint = min(mint + 1, temp[i]);
            L[i] = mint;
        }

        mint = INT_MAX;
        vector<LL> R(n, INT_MAX);
        for (int i = n - 1; i >= 0; --i) {
            mint = min(mint + 1, temp[i]);
            R[i] = mint;
        }

        for (int i = 0; i < n; ++i) {
            cout << min(L[i], R[i]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}

