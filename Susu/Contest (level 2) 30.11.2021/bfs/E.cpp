
/*
    author: MrS4g0
    created: 06.12.2021 14:04:43
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

constexpr int MOD = 101111;


enum button {
    DEL_TWO = '2',
    MUL_THREE = '3',
    ADD_FIVE = '5',
    SUB_SEVEN = '7'
};

struct button_s {
    int num;
    char but;
    vector<char> path;
};

int K, N;
queue<button_s> q;
map<int,bool> used;

inline void initQ() {
    q.push({ K, DEL_TWO });
    q.push({ K, MUL_THREE });
    q.push({ K, ADD_FIVE });
    q.push({ K, SUB_SEVEN });
}

inline void pushQ(int n, vector<char>&& p) {
    q.push({ n, DEL_TWO, p });
    q.push({ n, MUL_THREE, p });
    q.push({ n, ADD_FIVE, p });
    q.push({ n, SUB_SEVEN, p });
}

map<char,function<int(int)>> do_operation = {
    { DEL_TWO,   [](int n) { return n / 2; } },
    { MUL_THREE, [](int n) { return (n * 3) % MOD; } },
    { ADD_FIVE,  [](int n) { return (n + 5) % MOD; } },
    { SUB_SEVEN, [](int n) { return (n -= 7) < 0 ? MOD + n : n; } }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> N;

    initQ();
    used[K] = true;

    vector<char> min_path;
    while (true) {
        button_s cur = move(q.front()); q.pop();
        int new_num = do_operation[cur.but](cur.num);
        if (used.count(new_num)) {
            continue;
        }
        used[new_num] = true;
        cur.path.push_back(cur.but);
        if (new_num == N) {
            min_path = move(cur.path);
            break;
        }
        pushQ(new_num, move(cur.path));
    }

    cout << min_path.size() << nl;
    for (const char c : min_path) {
        cout << c;
    }
    cout << nl;

    return 0;
}

