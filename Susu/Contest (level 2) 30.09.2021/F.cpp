
/*
    author: MrS4g0
    created: 06.10.2021 22:21:19
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int iter = 0;

ull func(vector<pair<char, int>> v) {
    ull f = 0, x = v[iter].second;
    ++iter;
    while (v[iter].first != 'e') {
        f += func(v);
    }
    if (f == 0) {
        ++f;
    }
    ++iter;
    return x * f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> st;

    int n; scanf("%d", &n); getchar();
    ull sum = 0;
    vector<pair<char, int>> v(n * 2);
    for (int i = 0; i < n * 2; ++i) {
        char s[10] = { '\0' };
        fgets(s, 10, stdin);
        v[i].first = s[0];
        if (s[0] != 'e') {
            int c; sscanf(s + 4, "%d", &c);
            v[i].second = c;
        } else {
            v[i].second = 0;
        }
    }

    while (iter < n * 2) {
        sum += func(v);
    }

    cout << sum << nl;

    return 0;
}

