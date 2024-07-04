
/*
ID: sagosag1
TASK: numtri
LANG: C++
*/

#include <fstream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  ifstream fin("numtri.in");
  ofstream fout("numtri.out");

  int R;
  fin >> R;

  vector<vector<int>> v(R);

  for (int i = 0; i < R; ++i) {
    v[i].resize(i + 1);
    for (int j = 0; j <= i; ++j) {
      fin >> v[i][j];
    }
  }

  for (int i = R - 2; i >= 0; --i) {
    for (int j = 0; j <= i; ++j) {
      v[i][j] += max(v[i + 1][j], v[i + 1][j + 1]);
    }
  }

  fout << v[0][0] << '\n';

  return 0;
}
