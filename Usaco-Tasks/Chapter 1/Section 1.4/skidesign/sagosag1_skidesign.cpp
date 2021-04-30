
/*
ID: sagosag1
TASK: skidesign
LANG: C++
*/

#include <fstream>
#include <climits>

#define MAX_N (1000)
#define MAX_RANGE (17)

using namespace std;

int hills[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");

    int N; fin >> N;
    for (int* ptr = hills, * end_ptr = hills + N; ptr != end_ptr; ++ptr) {
        fin >> *ptr;
    }

    int res = INT_MAX;
    for (int i = 0; i <= 83; ++i) {
        int current = 0;
        for (int* ptr = hills, * end_ptr = hills + N; ptr != end_ptr; ++ptr) {
            int x, h = *ptr;
            if (h < i) {
                x = i - h;
            } else if (h > i + MAX_RANGE) {
                x = h - (i + MAX_RANGE);
            } else {
                continue;
            }
            current += x * x;
        }
        res = min(res, current);
    }

    fout << res << '\n';

    return 0;
}

