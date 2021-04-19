
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    vector<int> res;
    uint64_t prod = 1;
    for (int i = 1; i < N - 1; ++i) {
        if (__gcd(i, N) == 1) {
            prod = (prod * (uint64_t)i) % N;
            res.push_back(i);
        }
    }
    if (prod == N - 1) {
        res.push_back(N - 1);
    }

    cout << res.size() << '\n';
    for (const auto& it : res) {
        cout << it << ' ';
    }
    cout << '\n';

    return 0;
}

