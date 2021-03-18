
/*
ID: sagosag1
TASK: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <map>


#define MAX_M (250)
#define MAX_SET (31626) //C(MAX_M + 2,2)

using namespace std;

struct result {
    int a, b;
    bool operator<(const result& _entry) const {
        return this->b < _entry.b;
    }
};

int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    int N, M;
    fin >> N >> M;

    set<int> S;
    for (int p = 0; p <= M; ++p) {
        for (int q = p; q <= M; ++q) {
            S.insert(p*p + q*q);
        }
    }

    for (auto i = S.begin(); i != S.end(); ++i) {
        fout << *i << '\n';
    }

    vector<result> res;
    auto i = S.begin(); ++i;
    for (/*empty*/; i != S.end(); ++i) {
        for (int j = 1; j != *S.rbegin(); ++j) {
            int sum = *i;
            bool ok = true;
            for (int k = 1; k < N; ++k) {
                sum += j;
                if (!S.count(sum)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                result in;
                in.a = *i; in.b = j;
                res.push_back(in);
            }
        }
    }

    sort(res.begin(), res.end());

    for (const auto& it : res) {
        fout << it.a << ' ' << it.b << '\n';
    }

    return 0;
}

