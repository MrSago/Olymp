
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int sz = (int)3e5;
vector<int> c(sz);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    auto start = c.begin(), end = start + n;
    for (auto it = start; it != end; ++it) {
        cin >> *it;
    }

    while (q--) {
        int a; cin >> a;
        auto f = find(start, end, a);
        cout << f - start + 1 << ' ';
        if (!q) {
            break;
        }
        for (; f != start; --f) {
            *f = *(f - 1);
        }
        c[0] = a;
    }
    cout << '\n';

    return 0;
}

