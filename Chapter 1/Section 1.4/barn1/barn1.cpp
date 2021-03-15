
/*
ID: sagosag1
TASK: barn1
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
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	

	return 0;
}

