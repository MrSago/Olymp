
/*
ID: sagosag1
TASK: barn1
LANG: C++
*/

#include <fstream>

using namespace std;

inline int cmp(const void* a, const void* b) {
	return (*(int*)a) - (*(int*)b);
}

int stalls[200];
int dist[199];

int main() {
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int M, S, C;
	fin >> M >> S >> C;

	if (M >= C) {
		fout << C << '\n';
		return 0;
	}

	for (int i = 0; i < C; ++i) {
		fin >> stalls[i];
	}

	qsort(stalls, C, sizeof(int), cmp);

	int size_dist = 0;
	for (int i = 0; i < C - 1; ++i) {
		int dif = stalls[i + 1] - stalls[i] - 1;
		if (dif > 0) {
			dist[size_dist++] = dif;
		}
	}

	qsort(dist, size_dist, sizeof(int), cmp);

	int res = C;
	for (
		int i = 0, j = size_dist;
		i < size_dist && j >= M;
		++i, --j
	) {
		res += dist[i];
	}

	fout << res << '\n';

	return 0;
}

