
/*
    author: MrS4g0
    created: 22.01.2022 13:03:18
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }


int arr[100];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int mx = 1, mn = 5;

    n = nxt();
    for (int i = 0; i < n; ++i) {
        arr[i] = nxt();
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }

    replace_if(arr, arr + n, [&mx](auto& val) {
        return val == mx;
    }, mn);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << nl;

    return 0;
}

