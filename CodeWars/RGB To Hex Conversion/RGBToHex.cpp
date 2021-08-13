
/*
    author: MrS4g0
    created: 13.08.2021 11:44:29
    kata link: https://www.codewars.com/kata/513e08acc600c94f01000001/train/cpp
*/

#include <string>

using namespace std;

class RGBToHex {
   public:
    static string rgb(int r, int g, int b) {
        r = r < 0 ? 0 : r > 255 ? 255 : r;
        g = g < 0 ? 0 : g > 255 ? 255 : g;
        b = b < 0 ? 0 : b > 255 ? 255 : b;
        char ans[7] = { '\0' };
        sprintf(ans, "%06X", r << 16 | g << 8 | b);
        return static_cast<string>(ans);
    }
};



#include <iostream>
#include <iomanip>
#include <map>
#include <cassert>

struct _rgb {
    int r, g, b;
    _rgb(int _r, int _g, int _b) :
        r(_r), g(_g), b(_b) {}
};

void simple_test() {
    map<string, _rgb> test_case = {
        { "000000", _rgb(0, 0, 0) },
        { "010203", _rgb(1, 2, 3) },
        { "FFFFFF", _rgb(255, 255, 255) },
        { "FEFDFC", _rgb(254, 253, 252) },
        { "00FF7D", _rgb(-20, 275, 125) }
    };
    cout << "\n=====================TEST=====================\n";
    cout << setw(15) << "Input" << setw(10) << "Output" << setw(10) << "Answer" << setw(11) << "Verdict\n";
    for (auto& it : test_case) {
        string out = RGBToHex::rgb(
            it.second.r, it.second.g, it.second.b
        );
        string rgb_str = '(' + to_string(it.second.r) + ", " + to_string(it.second.g) + ", " + to_string(it.second.b) + ")";
        cout << setw(15) << rgb_str
             << setw(10) << out
             << setw(10) << it.first
             << setw(10) << (out == it.first ? "ACCEPTED" : "FAILED") << '\n';
    }
    cout << "==============================================\n\n";
}

int main() {
    assert(freopen("result.txt", "w", stdout));
    simple_test();
    return 0;
}

