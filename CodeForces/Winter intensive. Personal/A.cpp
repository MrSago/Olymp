
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int count = 0;
    while (n) {
        if (n >= 100) {
            count += n / 100;
            n %= 100;
        } else if (n >= 20) {
            count += n / 20;
            n %= 20;
        } else if (n >= 10) {
            count += n / 10;
            n %= 10;
        } else if (n >= 5) {
            count += n / 5;
            n %= 5;
        } else {
            count += n;
            n = 0;
        }
    }

    cout << count << '\n';

    return 0;
}

