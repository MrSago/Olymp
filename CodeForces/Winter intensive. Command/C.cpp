
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c, d, n, m, k;
    cin >> c >> d >> n >> m >> k;
    
    if (k >= n * m) {
        cout << "0\n";
        return 0;
    }

    int p = n * m - k;
    int a1 = (p / n + min(1, p % n)) * c;
    int a2 = p * d;
    int a3 = (p / n) * c + (p % n) * d;

    cout << min(min(a1, a2), a3);

    return 0;
}

