
/*
ID: sagosag1
TASK: sort3
LANG: C++
*/

#include <fstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  ifstream fin("sort3.in");
  ofstream fout("sort3.out");

  int arr[1000];
  int counts[3] = {0};
  int N;
  fin >> N;

  for (int i = 0; i < N; ++i) {
    fin >> arr[i];
    ++counts[arr[i] - 1];
  }

  int c12 = 0, c13 = 0;  // 2s in seg1, 3s in seg1
  int c21 = 0, c23 = 0;  // 1s in seg2, 3s in seg2
  int c31 = 0, c32 = 0;  // 1s in seg3, 2s in seg3

  for (int i = 0; i < counts[0]; ++i) {
    c12 += arr[i] == 2;
    c13 += arr[i] == 3;
  }
  for (int i = counts[0]; i < counts[0] + counts[1]; ++i) {
    c21 += arr[i] == 1;
    c23 += arr[i] == 3;
  }
  for (int i = counts[0] + counts[1]; i < N; ++i) {
    c31 += arr[i] == 1;
    c32 += arr[i] == 2;
  }

  fout << min(c12, c21) + min(c23, c32) + min(c31, c13) +
              2 * (max(c12, c21) - min(c12, c21))
       << '\n';

  return 0;
}
