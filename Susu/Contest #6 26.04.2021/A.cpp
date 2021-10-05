
#include <iostream>

using namespace std;

bool a[1000];
bool b[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s; cin >> n >> s; --s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }   

    if (!a[0]) {
        cout << "NO\n";
        return 0;
    }
    if (a[s]) {
        cout << "YES\n";
        return 0;
    }
    if (!b[s]) {
        cout << "NO\n";
        return 0;
    }
    for (int i = s + 1; i < n; ++i) {
        if (a[i] && b[i]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}

