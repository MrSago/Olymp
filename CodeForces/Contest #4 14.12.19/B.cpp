
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    cout << (uint64_t)powl(3, N) - (N - 1) << '\n';

    return 0;
}

