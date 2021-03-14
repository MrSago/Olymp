
/*
ID: sagosag1
TASK: crypt1
LANG: C++
*/

#include <fstream>
#include <vector>

using namespace std;

vector<int> crypt;

inline bool check(int num) {
	while (num) {
		int digit = num % 10;
		bool flag = false;
		for (auto it : crypt) {
			if (digit == it) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			return false;
		}
		num /= 10;
	}
	return true;
}

int main() {
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int N; fin >> N;
	crypt.resize(N);
	for (int i = 0; i < N; ++i) {
		fin >> crypt[i];
	}

	int res = 0;
	for (int i = 100; i <= 999; ++i) {
		for (int j = 10; j <= 99; ++j) {
			int p1 = i * (j % 10);
			int p2 = i * (j / 10);
			int prod = i * j;
			if (p1 <= 999 &&
				p2 <= 999 &&
				prod <= 9999 &&
				check(i) &&
				check(j) &&
				check(p1) &&
				check(p2) &&
				check(prod)
			) {
				++res;
			}
		}
	}
	
	fout << res << '\n';

	return 0;
}

