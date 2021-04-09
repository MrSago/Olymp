
#include <iostream>

using namespace std;

int m[100], c[100];
int p[10001][101] = { { 0 } };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> m[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> c[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (m[i - 1] <= j) {
                p[j][i] = max(p[j][i - 1], p[j - m[i - 1]][i - 1] + c[i - 1]);
            } else {
                p[j][i] = p[j][i - 1];
            }
        }
    }

    cout << p[M][N] << '\n';

    return 0;
}

