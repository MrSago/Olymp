
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int64_t res = \
        max(e, f) == e ? \
            min(a, d) == a ? \
                e * a + f * min(min(b, c), d - a) : \
            e * d : \
        min(min(b, c), d) == d ? \
            f * d : \
        f * min(b, c) + e * min(d - min(b, c), a);

    cout << res << '\n';

    return 0;
}

