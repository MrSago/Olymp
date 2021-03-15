
/*
ID: sagosag1
TASK: milk
LANG: C++
*/

#include <fstream>

using namespace std;

struct farm {
	int price;
	int amount;
};

inline int cmp(const void* a, const void* b) {
	return ((farm*)a)->price - ((farm*)b)->price;
}

farm data[5000];

int main() {
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int N, M;
	fin >> N >> M;
	for (int i = 0; i < M; ++i) {
		fin >> data[i].price >> data[i].amount;
	}

	qsort(data, M, sizeof(farm), cmp);

	int cost = 0;
	for (int i = 0; i < M; ++i) {
		N -= data[i].amount;
		if (N < 0) {
			cost += data[i].price * (data[i].amount + N);
			break;
		}
		cost += data[i].price * data[i].amount;
	}

	fout << cost << '\n';

	return 0;
}

