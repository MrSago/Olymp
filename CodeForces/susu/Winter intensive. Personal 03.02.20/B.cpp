
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int prev; cin >> prev;
    int count = 1, max_count = 1;
    for (int i = 1; i < n; ++i) {
        int cur; cin >> cur;
        if (cur >= prev) {
            ++count;
        } else {
            max_count = max(max_count, count);
            count = 1;
        }
        prev = cur;
    }
    
    cout << max(max_count, count) << '\n';

    return 0;
}

