
/*
ID: sagosag1
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");

	int N;
	fin >> N;

	vector<string> enumerate;
	map<string, int> data;

	for (int i = 0; i < N; ++i) {
		string in;
		fin >> in;
		enumerate.push_back(in);
		data.insert(pair<string, int>(in, 0));
	}

	for (int i = 0; i < N; ++i) {
		string giver;
		fin >> giver;
		int money, count;
		fin >> money >> count;

		if (count == 0) {
			continue;
		}

		if (money == 0) {
			for (int j = 0; j < count; ++j) {
				string skip;
				fin >> skip;
			}
		}

		data[giver] -= money - (money % count);

		for (int j = 0; j < count; ++j) {
			string lucky;
			fin >> lucky;
			data[lucky] += money / count;
		}
	}

	for (auto& it : enumerate) {
		fout << it << ' ' << data[it] << '\n';
	}

	return 0;
}
