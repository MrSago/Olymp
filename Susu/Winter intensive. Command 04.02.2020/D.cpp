
#include <iostream>

using namespace std;

constexpr int MOD = (int)1e9 + 7;
constexpr int MAX_STR = (int)1e5 + 2;
int fib[MAX_STR];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    if (s.find('w') != string::npos || s.find('m') != string::npos) {
        cout << "0\n";
        return 0;
    }

    fib[0] = fib[1] = 1;
    for (int i = 2; i < MAX_STR; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    uint64_t res = 1;
    for (size_t i = 0, j = 0; i < s.size(); i = j) {
        while (j < s.size() && s[i] == s[j]) ++j;
        if (s[i] == 'u' || s[i] == 'n') {
            res = res * (uint64_t)fib[j - i] % MOD;
        }
    }

    cout << res << '\n';

    return 0;
}

