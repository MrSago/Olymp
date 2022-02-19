
/*
    author: MrS4g0
    created: 22.01.2022 13:25:13
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }


map<char,char> phone = {
    { 'a', '2' }, { 'b', '2' }, { 'c', '2' },
    { 'd', '3' }, { 'e', '3' }, { 'f', '3' },
    { 'g', '4' }, { 'h', '4' }, { 'i', '4' },
    { 'j', '5' }, { 'k', '5' }, { 'l', '5' },
    { 'm', '6' }, { 'n', '6' }, { 'o', '6' },
    { 'p', '7' }, { 'q', '7' }, { 'r', '7' }, { 's', '7' },
    { 't', '8' }, { 'u', '8' }, { 'v', '8' },
    { 'w', '9' }, { 'x', '9' }, { 'y', '2' }, { 'z', '9' }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> res;

    int n = nxt();
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        string num;
        for (auto& it : input) {
            num.push_back(phone[it]);
        }
        res.insert(move(num));
    }

    cout << res.size() << nl;

    return 0;
}

