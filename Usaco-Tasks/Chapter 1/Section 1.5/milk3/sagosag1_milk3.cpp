
/*
ID: sagosag1
TASK: milk3
LANG: C++
*/

#include <fstream>

using namespace std;

int A, B, C;
bool pos[21][21] = {{false}};

inline void rec(int c = C, int b = 0) {
  if (pos[c][b]) {
    return;
  }
  pos[c][b] = true;
  int a = C - b - c;

  if (c + b > B)
    rec(c - (B - b), B);
  else
    rec(0, c + b);

  if (c + a > A)
    rec(c - (A - a), b);
  else
    rec(0, b);

  if (b + c > C)
    rec(C, b - (C - c));
  else
    rec(b + c, 0);

  if (b + a > A)
    rec(c, b - (A - a));
  else
    rec(c, 0);

  if (a + c > C)
    rec(C, b);
  else
    rec(a + c, b);

  if (a + b > B)
    rec(c, B);
  else
    rec(c, a + b);
}

int main() {
  ios::sync_with_stdio(false);
  ifstream fin("milk3.in");
  ofstream fout("milk3.out");

  fin >> A >> B >> C;

  rec();

  for (int i = 0; i <= C; ++i) {
    if (pos[i][C - i]) {
      if (i != C - B && i != 0) {
        fout << ' ';
      }
      fout << i;
    }
  }
  fout << '\n';

  return 0;
}
