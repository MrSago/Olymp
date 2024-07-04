
/*
  author: MrS4g0
  created: 26.06.2024 15:46:59
  kata link: https://www.codewars.com/kata/5254ca2719453dcc0b00027d/cpp
*/

#include <bits/stdc++.h>

std::vector<std::string> permutations(std::string s) {
  std::sort(s.begin(), s.end());
  std::vector<std::string> result;
  do {
    result.push_back(s);
  } while (std::next_permutation(s.begin(), s.end()));
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  auto res = permutations("abc");
  for (auto& it : res) {
    std::cout << it << '\n';
  }

  return 0;
}
