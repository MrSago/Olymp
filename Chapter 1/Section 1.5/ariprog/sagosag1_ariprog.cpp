
/*
ID: sagosag1
TASK: ariprog
LANG: C++
*/

#define _DEBUG_ON

#ifdef _DEBUG_ON
#include <chrono>
#include <iostream>
#endif

#include <fstream>
#include <algorithm>
#include <set>

//#define MAX_M (250)
//#define MAX_SET (31626) //C(MAX_M + 2,2)
#define MAX_RES (10000)

using namespace std;

struct result {
    int a, b;
    bool operator<(const result& _entry) const {
        return b < _entry.b;
    }
};

int res_count = 0;
result res[MAX_RES];

int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    int N, M;
    fin >> N >> M;

#ifdef _DEBUG_ON
    auto start1 = chrono::high_resolution_clock::now();
#endif
    set<int> S;
    for (int p = 0; p <= M; ++p) {
        int sq_p = p*p;
        for (int q = p; q <= M; ++q) {
            S.insert(sq_p + q*q);
        }
    }
#ifdef _DEBUG_ON
    auto stop1 = chrono::high_resolution_clock::now();
#endif

#ifdef _DEBUG_ON
    auto start2 = chrono::high_resolution_clock::now();
#endif
    int S_end_value = *S.rbegin();
    auto S_end_it = S.end();
    for (auto it = S.begin(); it != S_end_it; ++it) {
        int i_val = *it;
        for (int j = 1; j != S_end_value; ++j) {
            int sum = i_val;
            bool ok = true;
            for (int k = 1; k < N; ++k) {
                sum += j;
                if (S.find(sum) == S_end_it) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                result* ptr = res + res_count++;
                ptr->a = i_val; ptr->b = j;
            }
            if (sum >= S_end_value) {
                break;
            }
        }
    }
#ifdef _DEBUG_ON
    auto stop2 = chrono::high_resolution_clock::now();
#endif

#ifdef _DEBUG_ON
    auto start3 = chrono::high_resolution_clock::now();
#endif
    if (res_count) {
        sort(res, res + res_count);
        for (int i = 0; i < res_count; ++i) {
            result* ptr = res + i;
            fout << ptr->a << ' ' << ptr->b << '\n';
        }
    } else {
        fout << "NONE\n";
    }
#ifdef _DEBUG_ON
    auto stop3 = chrono::high_resolution_clock::now();
#endif

#ifdef _DEBUG_ON
    cout << "section1: " << (stop1 - start1).count() * 1e-9 << '\n';
    cout << "section2: " << (stop2 - start2).count() * 1e-9 << '\n';
    cout << "section3: " << (stop3 - start3).count() * 1e-9 << '\n';
#endif

    return 0;
}

