
/*
ID: sagosag1
TASK: skidesign
LANG: C++
*/

#include <fstream>
#include <climits>

#define MAX_N (1000)
#define MAX_DIF (17)

using namespace std;

int hills[MAX_N];

int main() {
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");

    int N; fin >> N;
    for (int i = 0; i < N; ++i) {
        fin >> hills[i];
    }

    int res = INT_MAX;
    for (int i = 0; i <= 83; ++i) {
        int current = 0;
        for (int j = 0; j < N; ++j) {
            int x;
            if (hills[j] < i) {
                x = i - hills[j];
            } else if (hills[j] > i + MAX_DIF) {
                x = hills[j] - (i + MAX_DIF);
            } else {
                x = 0;
            }
            current += x * x;
        }
        res = min(res, current);
    }

    fout << res << '\n';

    return 0;
}

