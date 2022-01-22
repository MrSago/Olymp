
/*
    author: MrS4g0
    created: 21.01.2022 19:21:31
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

struct sym {
    char c;
    int count;
    bool operator<(const sym& input) const {
        return count < input.count;
    };
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<char,int> m = {
        { 'a', 0 },
        { 'b', 0 },
        { 'c', 0 }
    };

    for (int i = 0; i < 3; ++i) {
        string buf;
        cin >> buf;
        if (buf[1] == '<') {
            --m[buf[0]];
            ++m[buf[2]];
        } else if (buf[1] == '>') {
            ++m[buf[0]];
            --m[buf[2]];
        }
    }

    multiset<sym> res;
    for (auto& [key, value] : m) {
        res.insert({ key, value });
    }

    for_each(res.begin(), res.end(), [](auto& val) {
        cout << val.c;
    });
    cout << nl;

    return 0;
}

