
/*
    author: MrS4g0
    created: 23.02.2022 03:14:39
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = nxt();
    cin.get();

    vector<int> q;

    while (N--) {
        string s;
        getline(cin, s);
        
        int pos;

        switch (s[0]) {
            case '+':
                q.push_back((int)strtol(&s.c_str()[2], NULL, 10));
            break;

            case '*':
                q.insert(q.begin() + q.size() / 2 + q.size() % 2, (int)strtol(&s.c_str()[2], NULL, 10));
            break;

            case '-':
                cout << q.front() << nl;
                q.erase(q.begin());
            break;

            default:
            break;
        }
    }

    return 0;
}
