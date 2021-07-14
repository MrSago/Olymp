
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int count = 0;
        while (n--) {
            int a; cin >> a;
            if (a == 1 || a == 3) {
                ++count;
            }
        }
        cout << count << '\n';
    }

    return 0;
}

