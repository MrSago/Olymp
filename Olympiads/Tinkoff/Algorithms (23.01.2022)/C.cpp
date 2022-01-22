
/*
    author: MrS4g0
    created: 22.01.2022 11:51:56
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, a, b;
    cin >> n >> k >> a >> b;
    cout << (a / b) + a / (min(n, k - 1) * b) << nl;

    return 0;
}

