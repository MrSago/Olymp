
/*
ID: sagosag1
TASK: milk2
LANG: C++
*/

#include <fstream>

using namespace std;

struct mtime {
  int start;
  int end;
};

inline int cmp(const void* a, const void* b) {
  return ((mtime*)a)->start - ((mtime*)b)->start;
}

mtime milk[5000];

int main() {
  ios::sync_with_stdio(false);
  ifstream fin("milk2.in");
  ofstream fout("milk2.out");

  int N;
  fin >> N;
  for (mtime *ptr = milk, *end_ptr = milk + N; ptr != end_ptr; ++ptr) {
    fin >> ptr->start >> ptr->end;
  }

  qsort(milk, N, sizeof(mtime), cmp);

  int tmilk = 0, tiddle = 0, icur = 0;
  for (int i = 1; i < N; ++i) {
    mtime *iptr = milk + i, *icur_ptr = milk + icur;
    int istart = iptr->start, icur_end = icur_ptr->end;
    if (istart > icur_end) {
      tiddle = max(tiddle, istart - icur_end);
      tmilk = max(tmilk, icur_end - icur_ptr->start);
      icur = i;
    } else {
      icur_ptr->end = max(icur_end, iptr->end);
    }
  }

  fout << max(tmilk, milk[icur].end - milk[icur].start) << ' ' << tiddle
       << '\n';

  return 0;
}
