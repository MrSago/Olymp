
/*
ID: sagosag1
TASK: wormhole
LANG: C++
*/

#include <fstream>
#include <algorithm>

#define MAX_N (12)

using namespace std;

struct wormhole {
    int x, y;
    bool operator<(const wormhole& _entry) const {
        return y != _entry.y ? y < _entry.y : x < _entry.x;
    }
};

int N;
wormhole wh[MAX_N + 1];
int pairs[MAX_N + 1] = { 0 };
int answer = 0;

inline bool find_cycle(int count, int now, int begin, bool paired) {
    if (count != 1 && now == begin && !paired) {
        return true;
    } else if (paired) {
        return find_cycle(count + 1, pairs[now], begin, false);
    } else if (wh[now].y == wh[now + 1].y) {
        return find_cycle(count + 1, now + 1, begin, true);
    }
    return false;
}

inline bool is_cycle() {
    for (int i = 1; i <= N; ++i) {
        if (find_cycle(1, i, i, false)) {
            return true;
        }
    }
    return false;
}

inline void find_pairs(int x = 1) {
    if (x > N) {
        answer += static_cast<int>(is_cycle());
    } else if (!pairs[x]) {
        for (int i = x + 1; i <= N; ++i) {
            if (!pairs[i]) {
                pairs[x] = i;
                pairs[i] = x;
                find_pairs(x + 1);
                pairs[x] = 0;
                pairs[i] = 0;
            }
        }
    } else {
        find_pairs(x + 1);
    }
}

int main() {
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    fin >> N;
    for (int i = 1; i <= N; ++i) {
        wormhole* ptr = wh + i;
        fin >> ptr->x >> ptr->y;
    }

    sort(wh + 1, wh + N + 1);
    find_pairs();

    fout << answer << '\n';

    return 0;
}

