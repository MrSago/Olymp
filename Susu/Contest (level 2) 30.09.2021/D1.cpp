
/*
    author: MrS4g0
    created: 07.10.2021 12:30:48
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using ll = long long;
using ull = unsigned long long;
using ld = long double;


pair<ull, ull> a[100001];
pair<ull, ull>* top = a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; scanf("%d", &n); getchar();

    for (int i = 0; i < n; ++i) {
        char c = getchar();
        if (c == '+') {
            ull x; scanf("%llu", &x);
            if (top == a) {
                *top = {x, x};
                ++top;
            } else {
                *top = {x, x + (top - 1)->second};
                ++top;
            }
        } else if (c == '?') {
            ull k; scanf("%llu", &k);
            printf("%llu\n", (top - 1)->second - (top - 1 - k)->second);
        } else {
            printf("%llu\n", (top - 1)->first);
            --top;
        }
        getchar();
    }

    return 0;
}

