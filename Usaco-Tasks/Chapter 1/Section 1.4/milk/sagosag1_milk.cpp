
/*
ID: sagosag1
TASK: milk
LANG: C++
*/

#include <fstream>

using namespace std;

struct farm {
  int price;
  int amount;
};

inline int cmp(const void* a, const void* b) {
  return ((farm*)a)->price - ((farm*)b)->price;
}

farm f[5000];

int main() {
  ios::sync_with_stdio(false);
  ifstream fin("milk.in");
  ofstream fout("milk.out");

  int N, M;
  fin >> N >> M;
  for (farm *ptr = f, *end_ptr = f + M; ptr != end_ptr; ++ptr) {
    fin >> ptr->price >> ptr->amount;
  }

  qsort(f, M, sizeof(farm), cmp);

  int cost = 0;
  for (farm *ptr = f, *end_ptr = f + M; ptr != end_ptr; ++ptr) {
    int pr = ptr->price, am = ptr->amount;
    N -= am;
    if (N < 0) {
      cost += pr * (am + N);
      break;
    }
    cost += pr * am;
  }

  fout << cost << '\n';

  return 0;
}
