
/*
ID: sagosag1
TASK: namenum
LANG: C++
*/

#include <fstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  ifstream fin("namenum.in");
  ofstream fout("namenum.out");
  ifstream dict("dict.txt");

  string num;
  fin >> num;

  bool found = false;
  string name;
  while (dict >> name) {
    if (name.length() == num.length()) {
      string res = "";
      for (const auto& c : name) {
        if (c == 'Q' || c == 'Z') {
          break;
        }
        if (c >= 'A' && c < 'Q') {
          res += ((c - 'A') / 3) + '2';
        } else if (c > 'Q' && c < 'Z') {
          res += ((c - 'Q') / 3) + '7';
        } else {
          break;
        }
      }
      if (res == num) {
        found = true;
        fout << name << '\n';
      }
    }
  }

  if (!found) {
    fout << "NONE\n";
  }

  return 0;
}
