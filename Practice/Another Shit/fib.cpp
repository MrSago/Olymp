
/*
    author: MrS4g0
    created: 12.10.2021 17:49:42
*/

#include <bits/stdc++.h>
using namespace std;


using uint128_t = unsigned __int128;
constexpr uint64_t base = static_cast<uint64_t>(1e19);

class BigNum {
private:
    vector<uint64_t> _v;

    void _fill_vec(string& input) {
        size_t i = input.length();
        for (; i >= 19; i -= 19) {
            _v.push_back(stoull(input.substr(i - 19, 19)));
        }
        if (i > 0) {
            _v.push_back(stoull(input.substr(0, i)));
        }
    }

public:
    BigNum() {}

    BigNum(string& num) {
        _fill_vec(num);
    }

    BigNum(const char num[]) {
        string s(num);
        _fill_vec(s);
    }

    BigNum(size_t vsz) : _v(vsz) {}

    BigNum(const int num) {
        _v.push_back(static_cast<uint64_t>(num));
    }

    // BigNum (const BigNum& obj) : _v(move(obj._v)) {}

    // BigNum (const BigNum&& obj) : _v(move(obj._v)) {}

    // BigNum& operator=(const BigNum& obj) {
    //     _v = move(obj._v);
    //     return *this;
    // }

    BigNum operator+(const BigNum& obj) {
        size_t mx = max(_v.size(), obj._v.size());
        bool carry = false;
        for (size_t i = 0; i < mx || carry; ++i) {
            if (i == _v.size()) {
                _v.push_back(0);
            }
            uint128_t cur = static_cast<uint128_t>(_v[i]) + (i < obj._v.size() ? obj._v[i] : 0) + carry ;
            carry = cur >= base;
            if (carry) {
                cur -= base;
            }
            _v[i] = static_cast<uint64_t>(cur);
        }
        return *this;
    }

    BigNum operator*(const BigNum& obj) {
        size_t lsz = _v.size(), rsz = obj._v.size();
        BigNum out(lsz + rsz);
        for (size_t i = 0; i < lsz; ++i) {
            for (size_t j = 0, carry = 0; j < rsz || carry; ++j) {
                uint128_t cur = out._v[i + j] + static_cast<uint128_t>(_v[i]) * (j < rsz ? obj._v[j] : 0) + carry;
                out._v[i + j] = static_cast<uint64_t>(cur % base);
                carry = static_cast<uint64_t>(cur / base);
            }
        }
        while (out._v.size() > 1 && out._v.back() == 0) {
            out._v.pop_back();
        }
        return out;
    }

    string get_str() {
        if (_v.empty()) {
            return string("0");
        }
        char s[20] = { '\0' };
        sprintf(s, "%llu", _v.back());
        string res = s;
        if (_v.size() > 2) {
            for (size_t i = _v.size() - 2; i > 0; --i) {
                sprintf(s, "%019llu", _v[i]);
                res += s;
            }
        }
        if (_v.size() >= 2) {
            sprintf(s, "%019llu", _v[0]);
            res += s;
        }
        return res;
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
        { 1, 0 },
        { 0, 1 }
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
    constexpr int N = 1000000;
    freopen("fib.out", "w", stdout);

    Matrix F01(matrix_v({
        { 0, 1 }
    }));
    Matrix P(matrix_v({
        { 0, 1 },
        { 1, 1 }
    }));

    cerr << "Calc fib...";
    auto start = std::chrono::high_resolution_clock::now();
    Matrix res = F01 * binpow_mat(P, N);
    auto stop = std::chrono::high_resolution_clock::now();
    cerr << "\nDone!\n";

    cout << "Calculation time: " << (stop - start).count() * 1e-9 << " ms\n";
    cout << "F(" << N << ") F(" << N + 1 << ")\n";
    res.print();

    return 0;
}

