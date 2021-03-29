
/*
ID: sagosag1
TASK: ariprog
LANG: C++
*/

#include <fstream>
#include <algorithm>

#define MAX_RES (10000)
#define MAX_BSQ (125000)

using namespace std;

struct result {
    int a, b;
    bool operator<(const result& _entry) const {
        return b < _entry.b;
    }
};

result res[MAX_RES];
bool bsq[MAX_BSQ] = { false };

int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    int N, M;
    fin >> N >> M;

    int res_count = 0;
    int bsq_size = M * M * 2;

    for (int p = 0; p <= M; ++p) {
        int sq_p = p * p;
        for (int q = p; q <= M; ++q) {
            bsq[sq_p + q * q] = true;
        }
    }

    result* res_ptr = res;
    for (int i = 0; i < bsq_size; ++i) {
        bool* i_ptr = bsq + i;
        if (!*i_ptr) {
            continue;
        }
        for (int j = 1; j <= (bsq_size - i) / (N - 1); ++j) {
            bool ok = true;
            for (int k = 1; k < N; ++k) {
                if (!*(i_ptr + j * k)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res_ptr->a = i; res_ptr->b = j;
                ++res_ptr; ++res_count;
            }
        }
    }

    if (res_count) {
        sort(res, res + res_count);
        for (result* ptr = res, * end_ptr = res + res_count; ptr != end_ptr; ++ptr) {
            fout << ptr->a << ' ' << ptr->b << '\n';
        }
    } else {
        fout << "NONE\n";
    }

    return 0;
}

