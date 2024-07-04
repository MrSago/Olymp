
/*
ID: sagosag1
TASK: frac1
LANG: C++
*/

#include <fstream>

using namespace std;

ofstream fout("frac1.out");
int N;

void frac(int n1, int d1, int n2, int d2) {
  if (d1 + d2 > N) {
    return;
  }
  frac(n1, d1, n1 + n2, d1 + d2);
  fout << n1 + n2 << '/' << d1 + d2 << '\n';
  frac(n1 + n2, d1 + d2, n2, d2);
}

int main() {
  ios::sync_with_stdio(false);
  ifstream fin("frac1.in");

  fin >> N;

  fout << "0/1\n";
  frac(0, 1, 1, 1);
  fout << "1/1\n";

  return 0;
}
