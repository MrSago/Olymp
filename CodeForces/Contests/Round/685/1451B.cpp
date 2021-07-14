
#include <bits/stdc++.h>

using namespace std;




int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	
	int tt;
	cin >> tt;
	
	while(tt--) {
		int n, k;
		cin >> n >> k;
		string a, b;
		cin >> a >> b;
		
		int m[26];
		memset(m, 0, sizeof(m));
		for (auto i: a) {
			++m[i-'a'];
		}
		for (auto i: b) {
			--m[i-'a'];
		}
		
		bool f=true;
		for (auto i: m) {
			f = f && i == 0;
		}
		if (f) {
			cout << "Yes\n";
		} else {
			f=true;
			int count = 0;
			for (auto i: m) {
				count += i;
				f = f && count >= 0 && i % k == 0;
			}
			if (f) {
				cout << "Yes\n";
			}
			else {
				cout << "No\n";
			}
		}
	}

	return 0;
}

