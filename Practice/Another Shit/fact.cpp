
#include <iostream>

using namespace std;

constexpr int MOD = (int)1e9 + 7;
constexpr int MAXN = 20;

template <int N>
struct precalc {
    int arr[N + 1];
    constexpr precalc() : arr() {
        arr[0] = 1;
        for (int i = 1; i <= N; i++) {
            arr[i] = (int)(arr[i - 1] * 1ll * i % MOD);
        }
    }
};

int main() {
    constexpr auto fact = precalc<MAXN>();
    for (auto& i : fact.arr) {
        cout << i << "\n";
    }
    return 0;
}

