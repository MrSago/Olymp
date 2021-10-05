
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        stack<int> s0, s1;
        while (n--) {
            int a; cin >> a;
            if (a % 2 == 0) {
                s0.push(a);
            } else {
                s1.push(a);
            }
        }
        n = s0.size();
        while (n--) {
            cout << s0.top() << ' ';
            s0.pop();
        }
        n = s1.size();
        while (n--) {
            cout << s1.top() << ' ';
            s1.pop();
        }
        cout << '\n';
    }

    return 0;
}

