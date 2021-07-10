
#include <iostream>

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
        int Ax = nxt(), Ay = nxt();
        int Bx = nxt(), By = nxt();
        int Fx = nxt(), Fy = nxt();

        if (Ax == Bx) {
            if (Ax == Fx && min(Ay, By) < Fy && Fy < max(Ay, By)) {
                cout << abs(Ay - By) + 2 << '\n';
            } else {
                cout << abs(Ay - By) << '\n';
            }
        } else if (Ay == By) {
            if (Ay == Fy && min(Ax, Bx) < Fx && Fx < max(Ax, Bx)) {
                cout << abs(Ax - Bx) + 2 << '\n';
            } else {
                cout << abs(Ax - Bx) << '\n';
            }
        } else {
            cout << abs(Ax - Bx) + abs(Ay - By) << '\n';
        }
    }

    return 0;
}

