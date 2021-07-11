
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

using LL = long long int;
using ULL = unsigned long long int;

template<typename T = int>
inline T nxt() {
    T x; cin >> x; return x;
}

vector<int> tree;

void build(int v, int l, int r, vector<int>& a) {
    if (l + 1 == r) {
        tree[v] = a[l];
    } else {
        int m = (l + r) >> 1;
        build(v * 2 + 1, l, m, a);
        build(v * 2 + 2, m, r, a);
        tree[v] = gcd(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) {
        return 0;
    }
    if (l <= tl && tr <= r) {
        return tree[v];
    }
    int m = (tl + tr) >> 1;
    return gcd(get (v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = nxt();
    while (tt--) {
        int n = nxt();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = nxt();
        }

        auto b = a;
        a.insert(a.end(), b.begin(), b.end());

        tree.resize(4 * a.size());
        build(0, 0, a.size(), a);

        int l = 0, r = n;
        while (l + 1 < r) {
            bool ok = true;
            int m = (l + r) >> 1;
            int g = get(0, 0, 2 * n, 0, m);
            for (int i = 1; i < n; ++i) {
                int gg = get(0, 0, 2 * n, i, m + i);
                if (g != gg) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                r = m;
            } else {
                l = m;
            }
        }

        cout << l << '\n';
    }

    return 0;
}

