
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

bool check(multiset<int>& ms) {
  if (ms.size() == 1 || ms.size() == 2) return true;

  int x1 = *ms.begin();
  int y1 = *ms.rbegin();
  int x2 = *ms.begin().operator++();
  int y2 = *ms.rbegin().operator--();

  if (y1 - x1 > 1) return false;

  if (x1 == y1) return true;

  if ((x1 == x2 && y1 != y2 && y1 - y2 == 1) ||
      (y1 == y2 && x1 != x2 && x2 - x1 == 1)) {
    return true;
  }

  return false;
}

void solve() {
  vi v(nxt());
  map<int, int> m;
  for (auto& val : v) {
    val = nxt();
    m[val]++;
  }

  multiset<int> ms;
  for (auto& [key, val] : m) {
    ms.insert(val);
  }

  for (int i = v.size() - 1; i > 0; --i) {
    bool ans = check(ms);
    if (!ans) {
      ms.erase(ms.lower_bound(m[v[i]]));
      --m[v[i]];
      if (m[v[i]] != 0) {
        ms.insert(m[v[i]]);
      }
    } else {
      if (ans) {
        cout << i + 1 << nl;
        return;
      } else {
        cout << i << nl;
        return;
      }
    }
  }

  cout << "1\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
