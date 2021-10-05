
/*
    author: MrS4g0
    created: 26.09.2021 11:29:01
*/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;


ull n, x, y, a, b, c, d;

inline ull nxt(ull i, ull& a0, ull& a1)
{
	if (i == 1) {
        return x;
    }
	if (i == 2) {
        return y;
    }
	ull a2 = (a0 * a + a1 * b + c) % d;
	a0 = a1;
	a1 = a2;
	return a2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> y >> a >> b >> c >> d;

    ull a0 = x, a1 = y;
    ull sum = x + y;

    for (ull i = 3; i <= n; ++i) {
        sum += nxt(i, a0, a1);
    }

    ull ix = 1, jx = n, j = 0, j0 = x, j1 = y, i0 = x, i1 = y;
    ull cur_sum = 0;

	for (ull i = 1; i <= n; i++) {
		while (j < n && cur_sum * 2 < sum) {
            j++;
            cur_sum += nxt(j, j0, j1);
        }

        if (j - i < jx - ix && cur_sum * 2 >= sum) {
			ix = i, jx = j;
		}

		nxt(i, i0, i1);

        if (i == 1) {
            cur_sum -= i0;
        } else {
            cur_sum -= i1;
        }
	}

    cout << ix << ' ' << jx << '\n';

    return 0;
}

