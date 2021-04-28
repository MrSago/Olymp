
#include <iostream>
#include <vector>

using namespace std;

char field[502][502];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<short,short>> sheeps;
    short R, C; cin >> R >> C;
    for (short i = 1; i <= R; ++i) {
        char* ptr_i = field[i];
        for (short j = 1; j <= C; ++j) {
            char c; cin >> c;
            if (c == '.') {
                ptr_i[j] = 'D';
                continue;
            }
            ptr_i[j] = c;
            if (c == 'S') {
                sheeps.push_back({ i, j });
            }
        }
        cin.ignore();
    }

    for (auto& it : sheeps) {
        if (
            field[it.first][it.second - 1] == 'W' ||
            field[it.first][it.second + 1] == 'W' ||
            field[it.first + 1][it.second] == 'W' ||
            field[it.first - 1][it.second] == 'W'
        ) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for (short i = 1; i <= R; ++i) {
        char* ptr_i = field[i];
        for (short j = 1; j <= C; ++j) {
            cout << ptr_i[j];
        }
        cout << '\n';
    }

    return 0;
}

