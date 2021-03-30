
#include <iostream>

using namespace std;

int citizens[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    int _max = -1;
    for (int* ptr = citizens, * end_ptr = citizens + N; ptr != end_ptr; ++ptr) {
        int in; cin >> in;
        if (in > _max) {
            _max = in;
        }
        *ptr = in;
    }

    int res = 0;
    for (int* ptr = citizens, * end_ptr = citizens + N; ptr != end_ptr; ++ptr) {
        res += _max - *ptr;
    }

    cout << res << '\n';

    return 0;
}
