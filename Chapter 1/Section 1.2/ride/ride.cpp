
/*
ID: sagosag1
TASK: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");

	string s1,s2;
	fin >> s1 >> s2;

	int prod1 = 1, prod2 = 1;
	for (auto& c: s1) {
		prod1 *= c-'A'+1;
	}
	for (auto& c: s2) {
		prod2 *= c-'A'+1;
	}

	if (prod1 % 47 == prod2 % 47) {
		fout << "GO\n";
	} else {
		fout << "STAY\n";
	}

	return 0;
}

