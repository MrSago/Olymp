
/*
ID: sagosag1
TASK: friday
LANG: C++
*/

#include <fstream>

using namespace std;

int main() {
	ifstream fin("friday.in");
	ofstream fout("friday.out");

	int count13[7] = { 0 };
	int m_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int offset = 0;
	int N; fin >> N;

	for (int i = 1900; i < 1900 + N; ++i) {
		for (int j = 0; j < 12; ++j) {
			count13[ (5 + offset) % 7 ] += 1;
			if (j == 1 && ((i % 100 != 0 && i % 4 == 0) || (i % 100 == 0 && i % 400 == 0))) {
				offset = (offset + 1) % 7;
			} else {
				offset = (offset + (m_days[j] % 7)) % 7;
			}
		}
	}

	fout << count13[5] << ' ' << count13[6] << ' ' << count13[0] << ' ' << count13[1] << ' ' << count13[2] << ' ' << count13[3] << ' ' << count13[4] << '\n';

	return 0;
}

