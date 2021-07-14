
#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	
	int tt;
	cin >> tt;
	
	while(tt--) {
		long long n, count = 0;
		cin >> n;
		
		if (n <= 3) cout << n-1 << '\n';
		else cout << (n&1) + 2 << '\n';
	}

	return 0;
}

