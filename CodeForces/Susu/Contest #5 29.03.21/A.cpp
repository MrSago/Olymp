
#include <iostream>
#include <cmath>

using namespace std;

inline bool sost(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    int n1 = N / 2, n2 = N - n1;
    while (1) {
        if (sost(n1) && sost(n2)) {
            cout << n1 << ' ' << n2 << '\n';
            return 0;
        }
        --n1; ++n2;
    }

    return 0;
}

