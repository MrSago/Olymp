
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

    if (r1 == r2 || c1 == c2) {
        cout << "1 ";
    } else {
        cout << "2 ";
    }

    int p1 = abs(r1 - r2), p2 = abs(c1 - c2);
    if ((r1 + c1) % 2 != (r2 + c2) % 2) {
        cout << "0 ";
    } else if (p1 == p2) {
        cout << "1 ";
    } else {
        cout << "2 ";
    }

    cout << max(p1, p2) << '\n';

    return 0;
}

