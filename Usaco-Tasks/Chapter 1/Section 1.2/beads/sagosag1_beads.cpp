
/*
ID: sagosag1
TASK: beads
LANG: C++
*/

#include <fstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  ifstream fin("beads.in");
  ofstream fout("beads.out");

  int N;
  string str;
  fin >> N >> str;

  int res = 0;
  str = str + str;
  for (int i = 0; i < N; ++i) {
    char c = str[i];
    int count = 0;
    int replaces;
    if (c == 'w') {
      replaces = 2;
    } else {
      replaces = 1;
    }
    int k = i, cmp = N + i;
    for (int j = 0; j <= replaces; ++j) {
      char c_k = str[k];
      for (/*empty*/; k < cmp && ((c_k = str[k]) == c || c_k == 'w'); ++k) {
        ++count;
      }
      c = c_k;
    }
    res = max(res, count);
  }

  fout << min(res, N) << '\n';

  return 0;
}
