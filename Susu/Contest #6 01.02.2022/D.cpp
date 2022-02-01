
/*
    author: MrS4g0
    created: 01.02.2022 09:32:59
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using i64 = long long;
using ui64 = unsigned long long;
using ld = long double;

// using i128 = __int128;
// using ui128 = unsigned __int128;
// inline i128 iget() { i64 x; cin >> x; return (i128)x; }
// inline ui128 uiget() { ui64 x; cin >> x; return (ui128)x; }

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vi64 = vector<i64>;
using vui64 = vector<ui64>;

using pi = pair<int,int>;
using pi64 = pair<i64,i64>;
using pui64 = pair<ui64,ui64>;
using graph = vector<vi>;

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }

constexpr int MOD = int(1e9) + 5;
constexpr int NMOD = 998244353;


/*
Complexity:
    build O(n)
    sum_tree O(logn)
    update O(logn)
Memory:
    O(4n)
Use:
    build(1, 0, n - 1);
    sum_tree(1, 0, n - 1, l, r);
    update(1, 0, n - 1, pos, new_val);
*/

constexpr int MAXN = int(1e5+10);
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
    return sum_tree(v << 1, tl, tm, l, min(r, tm)) +
           sum_tree((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            update(v << 1, tl, tm, pos, new_val);
        } else {
            update((v << 1) + 1, tm + 1, tr, pos, new_val);
        }
        tree[v] = tree[v << 1] + tree[(v << 1) + 1];
    }
}


int main() {
    a.assign(MAXN, 0);
    build(1, 0, MAXN - 1);

    int K;
    scanf("%d", &K); getchar();
    for (int k = 0; k < K; ++k) {
        char c = (char)getchar();
        getchar();

        int i, j;
        scanf("%d %d", &i, &j);
        getchar();

        if (c == 'S') {
            update(1, 0, MAXN - 1, i, j);
        } else if (c == 'Q') {
            cout << sum_tree(1, 0, MAXN - 1, i, j) << nl;
        } else {
            throw runtime_error("ggwp");
        }
    }

    return 0;
}

