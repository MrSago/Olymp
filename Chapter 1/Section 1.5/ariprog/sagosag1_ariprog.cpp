
/*
ID: sagosag1
TASK: ariprog
LANG: C++
*/

#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

//#define MAX_M (250)
//#define MAX_SET (31626) //C(MAX_M + 2,2)

using namespace std;

struct result {
    int a, b;
    result(int _a, int _b) : a(_a), b(_b) {}
    bool operator<(const result& _entry) const {
        return b < _entry.b;
    }
};

int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    int N, M;
    fin >> N >> M;

    set<int> S;
    for (int p = 0; p <= M; ++p) {
        int sq_p = p*p;
        for (int q = p; q <= M; ++q) {
            S.insert(sq_p + q*q);
        }
    }

    vector<result> res;
    for (auto i = S.begin(); i != S.end(); ++i) {
        int i_val = *i;
        for (int j = 1; j != *S.rbegin(); ++j) {
            int sum = i_val;
            bool ok = true;
            for (int k = 1; k < N; ++k) {
                sum += j;
                if (S.find(sum) == S.end()) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res.push_back(result(i_val, j));
            }
        }
    }

    if (res.size()) {
        sort(res.begin(), res.end());
        for (const auto& it : res) {
            fout << it.a << ' ' << it.b << '\n';
        }
    } else {
        fout << "NONE\n";
    }

    return 0;
}

