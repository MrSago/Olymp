
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int* F[3];for(int i=0;i<3;++i)F[i]=new int[N + 1];

    F[0][0] = F[1][0] = F[2][0] = 0;
    F[0][1] = F[1][1] = F[2][1] = 1;

    for (int i = 2; i < N + 1; ++i) {
        F[0][i] = F[0][i - 1] + F[1][i - 1] + F[2][i - 1];
        F[1][i] = F[0][i - 1] + F[2][i - 1];
        F[2][i] = F[0][i - 1] + F[1][i - 1] + F[2][i - 1];
    }

    cout << F[0][N] + F[1][N] + F[2][N] << '\n';

    for(int i=0;i<3;++i)delete[]F[i];
    return 0;
}

