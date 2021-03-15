
/*
ID: sagosag1
TASK: transform
LANG: C++
*/

#include <fstream>

using namespace std;

class Solution {
private:
	bool** mat; // '@' == true == 1
	bool** res; // '-' == false == 0
	uint8_t size;

	// Pattern #1
	inline bool rotate90() {
		for (uint8_t i = 0; i < size; ++i) {
			for (uint8_t j = 0; j < size; ++j) {
				if (mat[i][j] != res[j][size - 1 - i]) {
					return false;
				}
			}
		}
		return true;
	}
	// Pattern #2
	inline bool rotate180() {
		for (uint8_t i = 0; i < size; ++i) {
			for (uint8_t j = 0; j < size; ++j) {
				if (mat[i][j] != res[size - 1 - i][size - 1 - j]) {
					return false;
				}
			}
		}
		return true;
	}
	// Pattern #3
	inline bool rotate270() {
		for (uint8_t i = 0; i < size; ++i) {
			for (uint8_t j = 0; j < size; ++j) {
				if (mat[i][j] != res[size - 1 - j][i]) {
					return false;
				}
			}
		}
		return true;
	}
	// Pattern #4
	inline bool reflectH() {
		for (uint8_t i = 0; i < size; ++i) {
			for (uint8_t j = 0; j < size; ++j) {
				if (mat[i][j] != res[i][size - 1 - j]) {
					return false;
				}
			}
		}
		return true;
	}
	// Pattern #5
	inline bool reflectV() {
		bool** tmp = new bool* [size];
		for (uint8_t i = 0; i < size; ++i) {
			tmp[i] = new bool [size];
			for (uint8_t j = 0; j < size; ++j) {
				tmp[i][j] = mat[size - 1 - i][j];
			}
		}
		bool** ptr = mat;
		mat = tmp;
		bool check = equal() || rotate90() || rotate180() || rotate270();
		mat = ptr;
		for (uint8_t i = 0; i < size; ++i) {
			delete[] tmp[i];
		}
		delete[] tmp;
		return check;
	}
	// Pattern #6
	inline bool equal() {
		for (uint8_t i = 0; i < size; ++i) {
			for (uint8_t j = 0; j < size; ++j) {
				if (mat[i][j] != res[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

public:
	Solution() {
		ifstream fin("transform.in");
		int tmp; fin >> tmp; fin.get();
		size = static_cast<uint8_t>(tmp);
		mat = new bool* [size];
		for (uint8_t i = 0; i < size; ++i) {
			mat[i] = new bool [size];
			for (uint8_t j = 0; j < size; ++j) {
				mat[i][j] = fin.get() == '@';
			}
			fin.get();
		}
		res = new bool* [size];
		for (uint8_t i = 0; i < size; ++i) {
			res[i] = new bool [size];
			for (uint8_t j = 0; j < size; ++j) {
				res[i][j] = fin.get() == '@';
			}
			fin.get();
		}
	}
	inline void getsolution() {
		ofstream fout("transform.out");
		if (rotate90())		{ fout << "1\n"; }
		else if (rotate180())	{ fout << "2\n"; }
		else if (rotate270())	{ fout << "3\n"; }
		else if (reflectH())	{ fout << "4\n"; }
		else if (reflectV())	{ fout << "5\n"; }
		else if (equal())   	{ fout << "6\n"; }
		else			{ fout << "7\n"; }
	}
	~Solution() {
		for (uint8_t i = 0; i < size; ++i) {
			delete[] mat[i];
			delete[] res[i];
		}
		delete[] mat;
		delete[] res;
	}
};

int main() {
	Solution s;
	s.getsolution();
	return 0;
}

