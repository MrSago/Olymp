
/*
ID: sagosag1
TASK: ride
LANG: C++
*/

#include <fstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  ifstream fin("ride.in");
  ofstream fout("ride.out");

  string s1, s2;
  fin >> s1 >> s2;
  int prod1 = 1, prod2 = 1;
  for (const auto& c : s1) {
    prod1 *= c - 'A' + 1;
  }
  for (const auto& c : s2) {
    prod2 *= c - 'A' + 1;
  }

  if (prod1 % 47 == prod2 % 47) {
    fout << "GO\n";
  } else {
    fout << "STAY\n";
  }

  return 0;
}
