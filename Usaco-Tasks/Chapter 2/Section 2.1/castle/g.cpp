#include <bits/stdc++.h>

using namespace std;


const char walls[] {'D', 'R', 'U', 'L'};


vector<char> getNotWalls(int number) {
    vector<char> temp;
    bool w[4] = { false };
    if (number == 0) {
        return temp;
    }
    while (number != 0) {
        if (number >= 8) {
            w[0] = true;
            number -= 8;
        }
        if (number >= 4) {
            w[1] = true;
            number -= 4;
        }
        if (number >= 2) {
            w[2] = true; 
            number -= 2;
        }
        if (number == 1) {
            w[3] = true;
            number--;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (!w[i])
            temp.push_back(walls[i]);
    }
    return temp;
}
int main() {
    //ios::sync_with_stdio(0);
    ifstream fin("castle.in");
    ofstream fout("test.txt");
    int M = 0, N = 0;
    fin >> M >> N;
    // vector<vector<string>> v(N*M);
    // for (auto& i : v) {
    //     int t;
    //     fin >> t;
    //     i = getNotWalls(t);
    // }
    // int counter = 0;
    // for (auto& i : v) {
    //     for (auto& j : i) {
    //         cout << j << " ";
    //     }
    //     if (counter == 7) {
    //         cout << "\n";
    //         counter = 0;
    //     }
    //     cout << "\n";
    // }


    char field[N + N - 1][M + M - 1];
    for (int i = 0; i < N + N - 1; ++i) {
        for (int j = 0; j < M + M - 1; ++j) {
            field[i][j] = '#';
        }
    }

    for (int i = 0; i < N + N - 1; i+=2) {
        for (int j = 0; j < M + M - 1; j+=2) {
            field[i][j] = ' ';
            int f; fin >> f;
            auto sp = getNotWalls(f);
            for (auto& k : sp) {
                switch (k) {
                    case 'D':
                        field[i+1][j] = ' ';
                        break;
                    case 'R':
                        field[i][j+1] = ' ';
                        break;
                    case 'U':
                        field[i-1][j] = ' ';
                        break;
                    case 'L':
                        field[i][j-1] = ' ';
                        break;
                }
            }
        }
    }
    for (int i = 0; i <= M+M; i++)
        cout << "# ";
    cout << "\n";
    for (auto& i : field) {
        cout << "# ";
        for (auto& j : i) {
            cout << j << ' ';
        }
        cout << "#";
        cout << '\n';
    }
    for (int i = 0; i <= M+M; i++)
        cout << "# ";
    cout << "\n";
    // system("cls");
    // gotoxy(0, 0);
    // cout << obj0[0];
    // gotoxy(0, 1);
    // cout << obj0[1];
    // gotoxy(0, 2);
    // cout << obj0[2];
    // gotoxy(5, 0);
    // cout << obj0[3];
    // gotoxy(5, 1);
    // cout << obj0[4];
    // gotoxy(5, 2);
    // cout << obj0[5];
    // gotoxy(5, 3);
    return 0;
}

