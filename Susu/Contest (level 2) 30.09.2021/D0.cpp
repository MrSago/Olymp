

/*
    author: MrS4g0
    created: 07.10.2021 12:30:48
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;
using vull = vector<ull>;

using pii = pair<int,int>;
using graph = vector<vi>;

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }


ull a[100001] = { 0 };
ull* top = a;
ull n, tree[4 * 100001] = { 0 };

void build(ull v, ull tl, ull tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        ull tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        tree[v] = tree[v << 1] + tree[(v << 1) + 1];
    }
}

ull sum_tree(ull v, ull tl, ull tr, ull l, ull r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return tree[v];
    }
    ull tm = (tl + tr) >> 1;
    return sum_tree (v << 1, tl, tm, l, min(r, tm)) +
           sum_tree ((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update (ull v, ull tl, ull tr, ull pos, ull new_val) {
	if (tl == tr) {
		tree[v] = new_val;
    }
	else {
		ull tm = (tl + tr) >> 1;
		if (pos <= tm) {
			update (v << 1, tl, tm, pos, new_val);
        } else {
			update ((v << 1) + 1, tm + 1, tr, pos, new_val);
        }
		tree[v] = tree[v << 1] + tree[(v << 1) + 1];
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d", &n); getchar();
    build(1, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        char c = getchar();
        if (c == '+') {
            ull x; scanf("%llu", &x);
            *top = x;
            ++top;
            update(1, 0, n - 1, top - a - 1, x);
        } else if (c == '?') {
            ull k; scanf("%llu", &k);
            printf("%llu\n", sum_tree(1, 0, n - 1, top - a - k, top - a - 1));
        } else {
            update(1, 0, n - 1, top - a - 1, 0);
            printf("%llu\n", *(top - 1));
            --top;
        }
        getchar();
    }

    return 0;
}

