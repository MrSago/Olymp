
/*
ID: sagosag1
TASK: combo
LANG: C++
*/

#include <fstream>
#include <cmath>

using namespace std;

struct key {
    int x, y, z;
};

int N;

inline bool checkdist(int a, int b) {
    int dist = abs(a - b);
    return dist <= 2 || N - dist <= 2;
}

int main() {
    ios::sync_with_stdio(false);
    ifstream fin("combo.in");
    ofstream fout("combo.out");

    fin >> N;
    key john, master;
    fin >> john.x >> john.y >> john.z;
    fin >> master.x >> master.y >> master.z;

    int res = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                if (
                    (checkdist(john.x, i) && checkdist(john.y, j) && checkdist(john.z, k)) ||
                    (checkdist(master.x, i) && checkdist(master.y, j) && checkdist(master.z, k))
                ) {
                    ++res;
                }
            }
        }
    }

    fout << res << '\n';

    return 0;
}

