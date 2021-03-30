
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k; cin >> k;

    int count = k / 2;
    cout << count << '\n';
    if (k - count * 2) {
        cout << "3 ";
        --count;
    }
    for (int i = 0; i < count; ++i) {
        cout << "2 ";
    }
    cout << '\n';

    return 0;
}

