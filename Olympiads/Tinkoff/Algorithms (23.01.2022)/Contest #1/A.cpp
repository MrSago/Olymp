
/*
    author: MrS4g0
    created: 18.02.2022 21:36:30
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2; cin >> s1 >> s2;
    map<char, int> m;
    
    for (auto& c : s1) {
        ++m[c];
    }
    for (auto& c : s2) {
        --m[c];
    }

    if (all_of(m.begin(), m.end(), [](auto& x) { return !x.second; })) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

