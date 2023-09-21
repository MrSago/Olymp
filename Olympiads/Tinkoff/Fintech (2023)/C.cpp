
#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using i64 = long long;
using ui64 = unsigned long long;
using ld = long double;

using i128 = __int128;
using ui128 = unsigned __int128;
inline i128 iget() {
  i64 x;
  cin >> x;
  return static_cast<i128>(x);
}
inline ui128 uiget() {
  ui64 x;
  cin >> x;
  return static_cast<ui128>(x);
}

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vi64 = vector<i64>;
using vui64 = vector<ui64>;

using pi = pair<int, int>;
using pi64 = pair<i64, i64>;
using pui64 = pair<ui64, ui64>;
using graph = vector<vi>;

template <typename T = int>
inline T nxt() {
  T x;
  cin >> x;
  return x;
}

constexpr int MOD = int(1e9) + 7;
constexpr int NMOD = 998244353;

void solve() {
  nxt();
  string s;
  cin >> s;

  int a, b, c, d;
  a = b = c = d = -1;
  int res = INT_MAX;
  for (int i = 0; i < s.size(); ++i) {
    a = (s[i] == 'a' ? i : a);
    b = (s[i] == 'b' ? i : b);
    c = (s[i] == 'c' ? i : c);
    d = (s[i] == 'd' ? i : d);
    if (a != -1 && b != -1 && c != -1 && d != -1) {
      int cur_dist = max({a, b, c, d}) - min({a, b, c, d}) + 1;
      if (cur_dist < res) res = cur_dist;
    }
  }
  cout << (res == INT_MAX ? -1 : res) << nl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
