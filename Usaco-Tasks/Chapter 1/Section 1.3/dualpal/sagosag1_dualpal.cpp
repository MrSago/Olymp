
/*
ID: sagosag1
TASK: dualpal
LANG: C++
*/

#include <fstream>

using namespace std;

inline void revstr(string& str) {
    size_t len = str.length();
    for (size_t i = 0; i < len / 2; ++i) {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}

inline string dectobase(int N, int B) {
    string str = "";
    while (N) {
        str += static_cast<char>(N % B) + '0';
        N /= B;
    }
    revstr(str);
    return str;
}

inline bool isPalindrom(string str) {
    size_t len = str.length();
    for (size_t i = 0; i < len; ++i) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

    int N, S; fin >> N >> S;
    for (int num = S + 1, N_count = 0; N_count < N; ++num) {
        for (int base = 2, base_count = 0; base <= 10; ++base) {
            string str_num = dectobase(num, base);
            if (isPalindrom(str_num)) {
                if (++base_count == 2) {
                    ++N_count;
                    fout << num << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}

