
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int64_t n, k; cin >> n >> k;
	string s; cin >> s;
	set<char> keys;
	while (k--) {
		char c; cin >> c;
		keys.insert(c);
	}

	int64_t res = 0;
	for (int64_t i = 0; i < n; ++i) {
		int64_t j = i;	
		while (j < n && keys.find(s[j]) != keys.end()) ++j;
		res += (j - i) * (j - i + 1) / 2;
		i = j;
	}

	cout << res << '\n';
	
	return 0;
}

