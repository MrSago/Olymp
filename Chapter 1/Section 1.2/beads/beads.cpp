
/*
ID: sagosag1
TASK: beads
LANG: C++
*/

#include <fstream>

using namespace std;

int main() {
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	int N; string str;
	fin >> N >> str;

	int res = 0;
	str = str + str;
	for (int i = 0; i < N; ++i) {
		char c = str[i];
		int count = 0;
		int replaces;

		if (c == 'w') {
			replaces = 2;
		} else {
			replaces = 1;
		}

		int k = i;
		for (int j = 0; j <= replaces; ++j) {
			for (/*empty*/; k < N + i && (str[k] == c || str[k] == 'w'); ++k) {
				count += 1;
			}
			c = str[k];
		}
		res = max(res, count);
	}

	fout << min(res, N) << '\n';

	return 0;
}

