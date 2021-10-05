
/*
    author: MrS4g0
    created: 25.09.2021 20:28:19
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int MAXN = int(3e5) + 1;
    char s[MAXN] = { '\0' };

    int n = 0;
    for (int c; (c = getchar()) != '\n' && c != EOF; ) {
        if (c != ' ') {
            s[n++] = c;
        }
    }

    vector<vector<size_t>> counting(n + 1, vector<size_t>(26));

    for (int i = 1; i < n + 1; ++i) {
        counting[i] = counting[i - 1];
        ++counting[i][s[i - 1] - 'a'];
    }

    size_t ans = 0;

    for (int i = 1; i < n - 1; ++i) {
        for (int j = 0; j < 26; ++j) {
            ans += counting[i][j] * (counting[n][j] - counting[i + 1][j]);
        }
    }

    cout << ans << '\n';

    return 0;
}

