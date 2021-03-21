
#include <bits/stdc++.h>

using namespace std;

#define MAX_N (10000000)

int N;
int lp[MAX_N + 1];
vector<int> pr;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> N;

    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }

    if (N % 2 != 0) {
        int dif = N - 2;
        if (
            dif == *pr.rbegin() ||
            dif == *(pr.rbegin() - 1) ||
            dif == *(pr.rbegin() - 2)
        ) {
            fout << 2 << ' ' << dif << '\n';
        }
        return 0;
    }

    int last_j = pr.size() - 1;
    for (int i = 0, i_pr = pr[i]; i_pr <= N / 2; i_pr = pr[++i]) {
        int dif = N - i_pr;
        for (int j = last_j, j_pr = pr[j]; j_pr >= dif; j_pr = pr[--j]) {
            if (j_pr == dif) {
                fout << i_pr << ' ' << j_pr << '\n';
                last_j = j;
                break;
            }
        }
    }

    return 0;
}

