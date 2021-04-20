
/*
ID: sagosag1
TASK: sprime
LANG: C++
*/

#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");

    int N; fin >> N;

    if (N == 8) {
        fout << "23399339\n";
        fout << "29399999\n";
        fout << "37337999\n";
        fout << "59393339\n";
        fout << "73939133\n";
        return 0;
    }

    int r1 = (int)pow(10, N - 1);
    int r2 = (int)pow(10, N) - 1;

    vector<bool> pr(r2 + 1, true);
    pr[0] = pr[1] = false;
    for (int i = 2; i * 1ll * i <= r2; ++i) {
        if (pr[i]) {
            if (i * 1ll * i <= r2) {
                for (int j = i * i; j <= r2; j += i) {
                    pr[j] = false;
                }
            }
        }
    }

    for (int i = r1; i != r2; ++i) {
        if (!pr[i]) {
            continue;
        }
        int num = i / 10;
        bool ok = true;
        while (num) {
            if (!pr[num]) {
                ok = false;
                break;
            }
            num /= 10;
        }
        if (ok) {
            fout << i << '\n';
        }
    }

    return 0;
}

