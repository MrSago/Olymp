
/*
ID: sagosag1
TASK: sort3
LANG: C++
*/

#include <fstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");

    int arr[1000];
    int counts[3] = { 0 };
    int N; fin >> N;

    if (N == 1) {
        fout << "0\n";
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        fin >> arr[i];
        ++counts[arr[i] - 1];
    }

    int index[2] = { counts[0], counts[0] + counts[1]};

    int res = 0;
    for (int i = 1, k = 0; i <= 2; ++i) {
        for (int j = 0; j < counts[i - 1]; ++j, ++k) {
            if (arr[k] != i) {
                bool swaped = false;
                int s = arr[k] == 2 ? index[0] : index[1];
                int e = arr[k] == 2 ? index[1] : N;
                for ( ; s < e; ++s) {
                    if (arr[s] == i) {
                        swap(arr[k], arr[s]);
                        ++res;
                        swaped = true;
                        break;
                    }
                }
                if (!swaped) {
                    s = arr[k] == 2 ? index[1] : index[0];
                    e = arr[k] == 2 ? N : index[1];
                    for (; s < e; ++s) {
                        if (arr[s] == i) {
                            swap(arr[k], arr[s]);
                            ++res;
                            break;
                        }
                    }
                }
            }
        }
    }

    fout << res << '\n';

    return 0;
}

