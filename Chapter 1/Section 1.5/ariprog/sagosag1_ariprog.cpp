
/*
ID: sagosag1
TASK: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <array>
#include <set>
#include <algorithm>

#define MAX_M (250)
#define MAX_SET (31626) //comb(MAX_M + 2,2)

using namespace std;

/*constexpr int comb(int n, int m) {

}*/

using set_t = array<int, MAX_SET>;

constexpr set_t calcset() {
    set_t res = { 0 };
    const set_t& ptr = res;
    for (int p = 0, i = 0; p <= MAX_M; ++p) {
        for (int q = p; q <= MAX_M; ++q) {
            const_cast<set_t::reference>(ptr[i++]) = p*p + q*q;
        }
    }
    return res;
}

constexpr set_t bisqrt = calcset();


int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    int N, M;
    fin >> N >> M;

    set<int> cpy(
        bisqrt.begin(),
        bisqrt.end()
    );

    for (const auto& it : cpy) {
        fout << it << '\n';
    }

    return 0;
}

