
#include <fstream>

using namespace std;

#define MAX_SIZE (100)

struct table {
    int x, y, p;
};

int n, m, k;
bool room[MAX_SIZE][MAX_SIZE] = { { false } };
table t[MAX_SIZE];

inline bool isfree(int x1, int x2, int y1, int y2) {
    for (int i = x1; i < x2; ++i) {
        for (int j = y1; j < y2; ++j) {
            if (room[i][j] == true) {
                return false;
            }
        }
    }
    return true;
}

inline bool check_room(table& _t) {
    switch (_t.p) {
    case 0:
        if (_t.x - 1 < 0 || _t.y - 1 < 0) {
            return false;
        }
        else {
            return isfree(_t.x - 1, _t.x, _t.y - 1, _t.y);
        }

    case 1:
        if (_t.x - 1 < 0 || _t.y + 1 >= m) {
            return false;
        }
        else {
            return isfree(_t.x - 1, _t.x, _t.y + 1, _t.y);
        }

    case 2:
        if (_t.x + 1 >= n || _t.y - 1 < 0) {
            return false;
        }
        else {
            return isfree(_t.x + 1, _t.x, _t.y - 1, _t.y);
        }

    case 3:
        if (_t.x + 1 >= n || _t.y + 1 >= m) {
            return false;
        }
        else {
            return isfree(_t.x + 1, _t.x, _t.y + 1, _t.y);
        }
    default:
        return false;
    }
    return false;
}

inline void fill_table(int x1, int x2, int y1, int y2) {
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            room[i][j] = true;
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        fin >> t[i].x >> t[i].y >> t[i].p;
    }

    for (int i = 0; i < k; ++i) {
        room[t[i].x][t[i].y] = true;
    }

    for (int i = 0; i < k; ++i) {
        while (check_room(t[i])) {
            switch (t[i].p) {
            case 0:
                fill_table(t[i].x - 1, t[i].x, t[i].y - 1, t[i].y);
                break;

            case 1:
                fill_table(t[i].x - 1, t[i].x, t[i].y, t[i].y + 1);
                break;

            case 2:
                fill_table(t[i].x, t[i].x + 1, t[i].y - 1, t[i].y);
                break;

            case 3:
                fill_table(t[i].x, t[i].x + 1, t[i].y, t[i].y + 1);
                break;
            default:
                break;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res += static_cast<int>(room[i][j]);
        }
    }

    return 0;
}

