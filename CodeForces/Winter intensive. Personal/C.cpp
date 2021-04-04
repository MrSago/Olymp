
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    if (n % 2 != 0) {
        cout << "0\n";
        return 0;
    }

    cout << (1 << (n / 2)) << '\n';

    return 0;
}

