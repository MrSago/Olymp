
/*
    author: MrS4g0
    created: 12.09.2021 10:54:05
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;


constexpr int MAX_SZ = 201 * 201;

int N, M;
bool used[MAX_SZ];
int dp[MAX_SZ];
queue<int> q;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d%d", &N, &M);
    getchar();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int cur = j + i * M;
            char c = getchar();
            if (c == '*') {
                q.push(cur);
                used[cur] = true;
            } else if (c == '#') {
                used[cur] = true;
            } else {
                used[cur] = false;
            }
        }
        getchar();
    }

    memset(dp, 0, sizeof(int) * N * M);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        int to = -1;
        int v_mod = v % M;

        // Left
        if (v_mod != 0) {
            to = v - 1;
            if (!used[to]) {
                used[to] = true;
                q.push(to);
                dp[to] = dp[v] + 1;
            }
        }
        // Right
        if (v_mod < M - 1) {
            to = v + 1;
            if (!used[to]) {
                used[to] = true;
                q.push(to);
                dp[to] = dp[v] + 1;
            }
        }
        // Up
        if (v > M) {
            to = v - M;
            if (!used[to]) {
                used[to] = true;
                q.push(to);
                dp[to] = dp[v] + 1;
            }
        }
        // Down
        if (v < (N - 1) * M) {
            to = v + M;
            if (!used[to]) {
                used[to] = true;
                q.push(to);
                dp[to] = dp[v] + 1;
            }
        }
    }

    cout << *max_element(dp, dp + N * M) << '\n';

    return 0;
}

