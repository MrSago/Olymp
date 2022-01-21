
/*
    author: MrS4g0
    created: 11.12.2021 12:14:29
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using i64 = long long;
using ui64 = unsigned long long;
using ld = long double;

// using i128 = __int128;
// using ui128 = unsigned __int128;
// inline i128 iget() { i64 x; cin >> x; return (i128)x; }
// inline ui128 uiget() { ui64 x; cin >> x; return (ui128)x; }

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vi64 = vector<i64>;
using vui64 = vector<ui64>;

using pi = pair<int,int>;
using pi64 = pair<i64,i64>;
using pui64 = pair<ui64,ui64>;
using graph = vector<vi>;

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }

constexpr int MOD = int(1e9) + 7;
constexpr int NMOD = 998244353;
int q = 0;
int f = 0;
int n,m;

char mas[310][310];

void proverka(int i, int j){

    if (j + 1 < m && mas[i-2][j+1] == '#' && mas[i-3][j+1] == '.'){
        f++;
        mas[i][j] = 'F';
        mas[i-1][j] = 'F';
        mas[i-2][j] = 'F';
        mas[i-2][j+1] = 'F';
        mas[i-3][j] = 'F';
        mas[i-4][j] = 'F';
        mas[i-4][j+1] = 'F';
        mas[i-4][j+2] = 'F';
    }else if (j - 1 > -1 && mas[i-2][j-1] == '#'){
        q++;
        mas[i][j] = 'Q';
        mas[i-1][j] = 'Q';
        mas[i-2][j] = 'Q';
        mas[i-2][j-1] = 'Q';
        mas[i-2][j-2] = 'Q';
        mas[i-3][j-2] = 'Q';
        mas[i-3][j] = 'Q';
        mas[i-4][j] = 'Q';
        mas[i-4][j-1] = 'Q';
        mas[i-4][j-2] = 'Q';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    n = nxt(); m = nxt();
    char tmp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> tmp;
            mas[i][j] = tmp;
        }
    }

    for (int i = n - 1; i > -1; i--){
        for (int j = 0; j < m; j++){
            if (mas[i][j] == '#'){
                proverka(i,j);
                
            }
        }
    }

    cout << q << " " << f << nl;
    return 0;
}

