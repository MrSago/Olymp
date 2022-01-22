
/*
    author: MrS4g0
    created: 21.01.2022 20:20:32
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }


int arr[int(1e5)];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    n = nxt();
    for (int i = 0; i < n; ++i) {
        arr[i] = nxt();
    }

    auto m = min_element(arr, arr + n, [](auto& a, auto& b) {
        return abs(a) < abs(b);
    });

    for (int* it = arr; it < m; ++it) {
        if (abs(*it) < abs(*(it + 1))) {
            cout << "No\n";
            return 0;
        }
        *it = *it > 0 ? -(*it) : *it;
    }

    for (int* it = m + 1; it < arr + n; ++it) {
        if (abs(*(it - 1)) > abs(*it)) {
            cout << "No\n";
            return 0;
        }
        *it = *it < 0 ? -(*it) : *it;
    }

    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << nl;

    return 0;
}

