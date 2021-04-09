
#include <iostream>

using namespace std;

int t[20][20];
int sum[20][20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> t[i][j];
        }
    }

    sum[0][0] = t[0][0];
    for (int i = 1; i < M; ++i) {
        sum[0][i] = sum[0][i - 1] + t[0][i];
    }
    for (int i = 1; i < N; ++i) {
        sum[i][0] = sum[i - 1][0] + t[i][0];
    }

    for (int y = 1; y < N; ++y) {
        for (int x = 1; x < M; ++x) {
            sum[y][x] = min(sum[y][x - 1], sum[y - 1][x]) + t[y][x];
        }
    }

    cout << sum[N - 1][M - 1] << '\n';

    return 0;
}

