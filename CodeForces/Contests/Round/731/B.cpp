
#include <iostream>
#include <cstring>

using namespace std;

template<typename T = int>
inline T nxt() {
    T x; cin >> x; return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = nxt();
    while (tt--) {
        char s[27] = { '\0' }; cin >> s;
        char* l = &s[0];
        char* r = &s[strlen(s) - 1];
        char last;
        if (*l > *r) {
            last = *l;
            ++l;
        } else {
            last = *r;
            --r;
        }

        bool ok = true;
        while (l <= r) {
            if (last - *l == 1) {
                last = *l;
                ++l;
            } else if (last - *r == 1) {
                last = *r;
                --r;
            } else {
                ok = false;
                break;
            }
        }

        cout << (ok && last == 'a' ? "YES\n" : "NO\n");
    }

    return 0;
}

