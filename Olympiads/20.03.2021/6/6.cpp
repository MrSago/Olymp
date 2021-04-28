
#include <fstream>
#include <climits>

using namespace std;

int M;
bool chet;

inline int find_path(int a, int b = 0) {
    if (a > M) {
        return INT_MIN;
    }

    if (a == M) {
        return 0;
    }

    if (a == 1) {
        return 2 + find_path(2, 1);
    }

    if (chet) {
        if (a * 2 <= M - b) {
            return 2 + find_path(a * 2, a);
        } else {
            return 1 + find_path(a + b, b);
        }
    } else {
        if (a % 2 == 0) {
            return 1 + find_path(a + b, b);
        } else {
            return 2 + find_path(a * 2, a);
        }
    }

    return INT_MIN;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int a, res; fin >> a >> M;
    chet = M % 2 == 0;

    if (a > M || (res = find_path(a)) < 0) {
        fout << "-1\n";
    }
    else {
        fout << res << '\n';
    }

    return 0;
}

