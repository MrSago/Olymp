
/*
    author: MrS4g0
    created: 01.10.2021 22:34:29
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


map<string,int> words;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char str[202] = { '\0' };
    while (fgets(str, 202, stdin)) {
        size_t len = strlen(str) - 1;
        for (size_t i = 0; i < len; ) {
            char w[22] = { '\0' };
            int j = 0;
            while (i < len) {
                char c = static_cast<char>(tolower(str[i++]));
                if (c >= 'a' && c <= 'z') {
                    w[j++] = c;
                } else {
                    break;
                }
            }
            if (j > 0) {
                ++words[w];
            }
        }
    }

    vector<pair<string,int>> dp(words.begin(), words.end());
    sort(dp.begin(), dp.end(),
         [](auto& a, auto& b) {
             if (a.second != b.second) {
                 return a.second > b.second;
             }
             if (a.first.length() != b.first.length()) {
                 return a.first.length() > b.first.length();
             }
             return a.first < b.first;
         }
    );

    int ans = 10;
    for (auto& it : dp) {
        if (ans--) {
            cout << it.first << '\n';
        } else {
            break;
        }
    }

    return 0;
}

