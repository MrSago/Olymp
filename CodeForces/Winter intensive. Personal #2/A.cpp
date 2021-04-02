
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

	int a1, a2; cin >> a1 >> a2;
	int res = 0;

	while (a1 > 0 && a2 > 0) {
		if (a1 == 1 && a2 == 1) {
			break;
		}
		if (a1 > a2) {
			a1 -= 2;
			a2 += 1;
		} else {
			a1 += 1;
			a2 -= 2;
		}
		++res;
	}

	cout << res << '\n';

	return 0;
}

