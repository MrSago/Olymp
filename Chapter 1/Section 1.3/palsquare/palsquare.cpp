
/*
ID: sagosag1
TASK: palsquare
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

inline string dectobase(int N, int B) {
	string str = "";
	while (N) {
		int tmp = N % B;
		str += tmp >= 0 && tmp <= 9 ? (char)tmp + '0' : (char)tmp - 10 + 'A';
		N /= B;
	}
	reverse(str.begin(), str.end());
	return str;
}

inline bool isPalindrom(string str) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] != str[str.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	int B; fin >> B;
	for (int N = 1; N <= 300; ++N) {
		string num = dectobase(N * N, B);
		if (isPalindrom(num)) {
			fout << dectobase(N, B) << ' ' << num << '\n';
		}
	}

	return 0;
}

