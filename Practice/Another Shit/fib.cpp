
/*
    author: MrS4g0
    created: 12.10.2021 17:49:42
*/

#include <bits/stdc++.h>
using namespace std;


constexpr int base = 1000000000;

class BigNum {
private:
    vector<int> _v;

    void _fill_vec(string& input) {
        for (int i = (int)input.length(); i > 0; i -= 9) {
            if (i < 9) {
                _v.push_back(atoi(input.substr(0, i).c_str()));
            } else {
                _v.push_back(atoi(input.substr(i - 9, 9).c_str()));
            }
        }
    }


public:
    BigNum() {}

    BigNum(string& num) {
        _fill_vec(num);
    }

    BigNum(const char num[]) {
        string s = num;
        _fill_vec(s);
    }

    BigNum(const int num) {
        if (num < base) {
            _v.push_back(num);
        } else {
            _v.push_back(num % base);
            _v.push_back(num / base);
        }
    }

    string get_str() {
        if (_v.empty()) {
            return string("0");
        }
        char s[10] = { '\0' };
        sprintf(s, "%d", _v.back());
        string res = s;
        for (int i = (int)_v.size() - 2; i >= 0; --i) {
            sprintf(s, "%09d", _v[i]);
            res += s;
        }
        return res;
    }

    BigNum operator+(const BigNum& in) {
        for (int i = 0, carry = 0; i < (int)max(_v.size(), in._v.size()) || carry; ++i) {
            if (i == (int)_v.size()) {
                _v.push_back(0);
            }
            _v[i] += carry + (i < (int)in._v.size() ? in._v[i] : 0);
            carry = _v[i] >= base;
            if (carry) {
                _v[i] -= base;
            }
        }
        return *this;
    }

    BigNum operator*(const BigNum& in) {
        BigNum out;
        out._v.resize(_v.size() + in._v.size());
        for (int i = 0; i < (int)_v.size(); ++i) {
            for (int j = 0, carry = 0; j < (int)in._v.size() || carry; ++j) {
                long long cur = out._v[i + j] + _v[i] * 1ll * (j < (int)in._v.size() ? in._v[j] : 0) + carry;
                out._v[i + j] = int(cur % base);
                carry = int(cur / base);
            }
        }
        while (out._v.size() > 1 && out._v.back() == 0) {
            out._v.pop_back();
        }
        return out;
    }
};


using matrix_v = vector<vector<BigNum>>;

class Matrix {
public:
    matrix_v _m;
    int str = 0, col = 0;

    Matrix() {}

    Matrix(matrix_v m) : _m(m) {
        str = (int)m.size();
        col = (int)m[0].size();
    }

    Matrix operator*(const Matrix& in) {
        if (col != in.str) {
            throw runtime_error("incorrect matrix sizes");
        }
        Matrix out;
        out.str = str;
        out.col = in.col;
        out._m.assign(out.str, vector<BigNum>(out.col));
        for (int i = 0; i < out.str; ++i) {
            for (int j = 0; j < out.col; ++j) {
                BigNum tmp = 0;
                for (int k = 0; k < out.col; ++k) {
                    tmp = tmp + (_m[i][k] * in._m[k][j]);
                }
                out._m[i][j] = tmp;
            }
        }
        return out;
    }

    void print() {
        for (int i = 0; i < str; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << _m[i][j].get_str() << ' ';
            }
            cout << '\n';
        }
    }
};


Matrix binpow_mat(Matrix a, unsigned n) {
    Matrix res(matrix_v({
        { "1", "0" },
        { "0", "1" }
    }));
    while (n) {
        if (n & 1) {
            res = res * a;
        }
        a = a * a;
        n >>= 1;
    }
    return res;
}


int main() {
    constexpr int N = 100;
    //freopen("out.txt", "w", stdout);

    Matrix F01(matrix_v(
        { { "0", "1" } }
    ));
    Matrix P(matrix_v({
        { "0", "1" },
        { "1", "1" }
    }));

    Matrix res = F01 * binpow_mat(P, N);

    cout << "F(" << N << ") F(" << N + 1 << ")\n";
    res.print();

    return 0;
}

