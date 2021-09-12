

/*
    author: MrS4g0
    created: 12.09.2021 19:38:01
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 2; i <= 36; ++i) {
        int n = N;
        vector<int> a;
        while (n) {
            a.push_back(n % i);
            n /= i;
        }
        sort(a.begin(), a.end());
        bool ans = true;
        for (int j = 0; j < (int)a.size() - 1; ++j) {
            if (a[j] == a[j + 1]) {
                ans = false;
                break;
            }
        }
        if (ans) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}

