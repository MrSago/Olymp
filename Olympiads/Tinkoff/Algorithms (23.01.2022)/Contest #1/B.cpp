
/*
    author: MrS4g0
    created: 18.02.2022 21:46:48
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> q;

    while (!cin.eof()) {
        string s;
        getline(cin, s);

        int n;

        switch (s[2]) {
            case 's': // push
                n = strtol(&s.c_str()[5], NULL, 10);
                q.push_back(n);
                cout << "ok\n";
            break;

            case 'p': // pop
                cout << q.front() << '\n';
                q.erase(q.begin());
            break;

            case 'o': // front
                cout << q.front() << '\n';
            break;

            case 'z': // size
                cout << q.size() << '\n';
            break;

            case 'e': // clear
                q.clear();
                cout << "ok\n";
            break;

            case 'i': // exit
                cout << "bye\n";
            return 0;

            default:
            break;
        }
    }

    return 0;
}

