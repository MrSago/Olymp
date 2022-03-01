
/*
    author: MrS4g0
    created: 23.02.2022 06:01:06
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> v;
    while (!cin.eof()) {
        v.push_back(nxt<string>());
    }

    sort(v.begin(), v.end(),
    [](auto& b, auto& a) {
        int a_len = a.length();
        int b_len = b.length();
        int len = a_len == b_len ? a_len : a_len + b_len;
        for (int i=0; i < len; i++) {
            char ac = i < a_len ? a[i] : b[i-a_len];
            char bc = i < b_len ? b[i] : a[i-b_len];
            if (ac == bc) continue;
            return ac < bc;
        }
        return false;
    });

    for (auto& it : v) {
        cout << it;
    }
    cout << nl;

    return 0;
}

