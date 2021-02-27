
/*
ID: sagosag1
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");

	int N;
	fin >> N;

	vector<map<string,int>> data(N);

	for (int i = 0; i < N; ++i) {
		string in;
		fin >> in;
		map<string,int> add {in, 0};
		data.push_back(add);
	}

	for (int i = 0; i < N; ++i) {
		string out;
		fin >> out;
		int gift, count;
		fin >> gift >> count;

		if (gift % count != 0) {
			data[out] -= gift - count;
		}

		for (int j = 0, j < count; ++j) {
			string in;
			fout >> in;
			data[in] += gift / count;
		}
	}

	return 0;
}

