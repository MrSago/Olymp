
/*
    author: MrS4g0
    created: 20.02.2022 19:27:19
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

struct costs {
    char c;
    int count;
    int price;
    bool operator<(costs inp) const {
        return price < inp.price;
    }
};

costs c[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    for (int i = 0; i < 26; ++i) {
        cin >> c[i].price;
        c[i].c = i + 'a';
    }

    for (int i = 0; i < (int)s.size(); ++i) {
        ++c[s[i] - 'a'].count;
    }

    sort(c, c + 26);

    deque<char> res;

    for (int i = 0; i < 26; ++i) {
        if (c[i].count == 0) {
            continue;
        }
        if (c[i].count == 1) {
            c[i].count = 0;
            res.push_back(c[i].c);
        } else if (c[i].count > 2) {
            for (int j = 0; j < c[i].count - 2; ++j) {
                res.push_back(c[i].c);
            }
            c[i].count = 2;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (c[i].count) {
            res.push_back(c[i].c);
            res.push_front(c[i].c);
        }
    }
    
    for (auto& it : res) {
        cout << it;
    }
    cout << nl;

    return 0;
}

