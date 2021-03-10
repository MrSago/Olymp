
/*
ID: sagosag1
TASK: dualpal
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

inline string dectobase(int N, int B) {
	string str = "";
	while (N) {
		str += (char)(N % B) + '0';
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
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int N, S; fin >> N >> S;
	for (int num = S + 1, N_count = 0; N_count < N; ++num) {
		for (int base = 2, base_count = 0; base <= 10; ++base) {
			string str_num = dectobase(num, base);
			if (isPalindrom(str_num)) {
				if (++base_count == 2) {
					++N_count;
					fout << num << '\n';
					break;
				}
			}
		}
	}

	return 0;
}

