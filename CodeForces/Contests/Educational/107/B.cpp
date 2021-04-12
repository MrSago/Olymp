
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        cout << '1';
        while (--a) {
            cout << '0';
        }
        cout << " 1";
        
        ++c;
        for (int i = b; i > 1; --i) {
            if (i == c) {
                cout << '1';
            } else {
                cout << '0';
            }
        }
        cout << '\n';
    }

    return 0;
}

