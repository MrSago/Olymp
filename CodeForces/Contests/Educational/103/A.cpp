
#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
			unsigned long long n, k; cin >> n >> k;
			if (n > k) {
				cout << (unsigned long long)ceil((ceil((long double)n/(long double)k) * (long double)k) / (long double)n) << '\n';
			}
			else {
				cout << (unsigned long long)ceil((long double)k/(long double)n) << '\n';
			}
		}
	return 0;
}

