
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

static constexpr int MAXN = (int)1e5;

vector<int> a;
int n, tree[4 * MAXN];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        tree[v] = tree[v << 1] + tree[(v << 1) + 1];
    }
}

int sum_tree(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) >> 1;
    return sum_tree (v << 1, tl, tm, l, min(r, tm)) +
           sum_tree ((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr) {
		tree[v] = new_val;
    }
	else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm) {
			update (v << 1, tl, tm, pos, new_val);
        } else {
			update ((v << 1) + 1, tm + 1, tr, pos, new_val);
        }
		tree[v] = tree[v << 1] + tree[(v << 1) + 1];
	}
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

