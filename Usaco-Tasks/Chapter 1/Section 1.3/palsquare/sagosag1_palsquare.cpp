
/*
ID: sagosag1
TASK: palsquare
LANG: C++
*/

#include <fstream>

using namespace std;

inline void revstr(string& str) {
  size_t len = str.length();
  for (size_t i = 0; i < len / 2; ++i) {
    auto tmp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = tmp;
  }
}

inline string dectobase(int N, int B) {
  string str = "";
  while (N) {
    char tmp = static_cast<char>(N % B);
    str += tmp >= 0x0 && tmp <= 0x9 ? tmp + '0' : tmp - 0xA + 'A';
    N /= B;
  }
  revstr(str);
  return str;
}

inline bool isPalindrom(string str) {
  size_t len = str.length();
  for (size_t i = 0; i < len; ++i) {
    if (str[i] != str[len - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  ifstream fin("palsquare.in");
  ofstream fout("palsquare.out");

  int B;
  fin >> B;

  for (int N = 1; N <= 300; ++N) {
    string num = dectobase(N * N, B);
    if (isPalindrom(num)) {
      fout << dectobase(N, B) << ' ' << num << '\n';
    }
  }

  return 0;
}
