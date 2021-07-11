
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

static constexpr int MAXN = (int)1e5;

vector<int> a;
int n, tree[4 * MAXN];

void build(int v, int l, int r) {
    if (l == r) {
        tree[v] = a[l];
    } else {
        int m = (l + r) >> 1;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int sum_tree(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return tree[v];
    }
    int m = (tl + tr) >> 1;
    return sum_tree (v * 2, tl, m, l, min(r, m))
         + sum_tree (v * 2 + 1, m + 1, tr, max(l, m + 1), r);
}

int main() {
    assert(freopen("segtree.in", "r", stdin));
    assert(freopen("segtree.out", "w", stdout));

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l, r; cin >> l >> r;

    build(1, 0, n - 1);
    cout << sum_tree(1, 0, n - 1, l, r);

    return 0;
}

