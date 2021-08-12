
/*
    author: MrS4g0
    created: 12.08.2021 15:36:06
    kata link: https://www.codewars.com/kata/51b66044bce5799a7f000003/train/cpp/6113c75f3069b100578df5ae
*/

#include <string>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

class RomanHelper {
private:
    map<char,int> alph = {
        { 'I', 1    },
        { 'V', 5    },
        { 'X', 10   },
        { 'L', 50   },
        { 'C', 100  },
        { 'D', 500  },
        { 'M', 1000 }
    };
    map<int,string> table = {
        { 1, "I"    }, { 10, "X"    }, { 100, "C"    }, { 1000, "M"   },
        { 2, "II"   }, { 20, "XX"   }, { 200, "CC"   }, { 2000, "MM"  },
        { 3, "III"  }, { 30, "XXX"  }, { 300, "CCC"  }, { 3000, "MMM" },
        { 4, "IV"   }, { 40, "XL"   }, { 400, "CD"   },
        { 5, "V"    }, { 50, "L"    }, { 500, "D"    },
        { 6, "VI"   }, { 60, "LX"   }, { 600, "DC"   },
        { 7, "VII"  }, { 70, "LXX"  }, { 700, "DCC"  },
        { 8, "VIII" }, { 80, "LXXX" }, { 800, "DCCC" },
        { 9, "IX"   }, { 90, "XC"   }, { 900, "CM"   }
    };

public:
    string to_roman(int n) {
        vector<string> res;
        for (int i = 0, a = 1; n > 0; ++i, a *= 10, n /= 10) {
            res.push_back(table[n % 10 * a]);
        }
        return accumulate(res.rbegin(), res.rend(), string{});
    }
    int from_roman(string inp) {
        char last = inp[inp.length() - 1];
        int ans = alph[last];
        for (int i = (int)inp.length() - 2; i >= 0; --i) {
            if (alph[inp[i]] >= alph[last]) {
                ans += alph[inp[i]];
            } else {
                ans -= alph[inp[i]];
            }
            last = inp[i];
        }
        return ans;
    }
} RomanNumerals;



#include <iostream>
#include <iomanip>
#include <cassert>
#include <chrono>

#define MAXN (3999)

void full_test() {
    long long t = 0;
    int fix = 20;

    cout << "\n=====================TEST=====================\n";
    cout << "Input" << setw(fix + 1) << right << "Result" << setw(fix) << right << "Verdict\n";
    for (int n = 1; n <= MAXN; ++n) {
        auto start = chrono::high_resolution_clock::now();
        string roman = RomanNumerals.to_roman(n);
        int arab = RomanNumerals.from_roman(roman);
        auto stop = chrono::high_resolution_clock::now();
        
        t += (stop - start).count();

        fix -= (n == 10 || n == 100 || n == 1000);
        cout << "n=" << n << setw(fix) << right << roman << '=' << arab << setw(fix) << right << (arab == n ? "ACCEPTED" : "FAIL") << '\n';
    }
    cout << "==============================================\n";

    long double full_time = (long double)t * (long double)1e-6;
    cout << "Full time: " << full_time << " ms\n";
    cout << "Avg time: " << full_time / MAXN << " ms\n\n";
}

int main() {
    assert(freopen("result.txt", "w", stdout));
    full_test();
    return 0;
}

