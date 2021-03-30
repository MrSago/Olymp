
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int count0 = 0, count1 = 0, max0 = -1;

    while (n--) {
        int a; cin >> a;
        if (a) {
            ++count1;
            if (count0) {
                --count0;
            }
        } else {
            ++count0;
            if (count0 > max0) {
                max0 = count0;
            }
        }
    }

    cout << count1 + max0 << '\n';

    return 0;
}

