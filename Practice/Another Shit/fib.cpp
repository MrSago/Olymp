
/*
    author: MrS4g0
    created: 12.10.2021 17:49:42
*/

#include <bits/stdc++.h>
#include <omp.h>
using namespace std;


constexpr int base = int(1e9);

class BigNum {
private:
    vector<int> _v;

    void _fill_vec(string& input) {
        size_t i = input.length();
        for (; i >= 9; i -= 9) {
            _v.push_back(stol(input.substr(i - 9, 9)));
        }
        if (i > 0) {
            _v.push_back(stol(input.substr(0, i)));
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

    BigNum(const size_t vsz) : _v(vsz) {}

    BigNum operator+(const BigNum& obj) {
        size_t mx = max(_v.size(), obj._v.size());
        BigNum out(mx);
        int carry = 0;
        for (size_t i = 0; i < mx || carry; ++i) {
            if (i == _v.size()) {
                out._v.push_back(0);
            }
            out._v[i] = _v[i] + carry + (i < obj._v.size() ? obj._v[i] : 0);
            carry = out._v[i] >= base;
            if (carry) {
                out._v[i] -= base;
            }
        }
        return out;
    }

    BigNum operator*(const BigNum& obj) {
        size_t lsz = _v.size(), rsz = obj._v.size();
        BigNum out(lsz + rsz);
        for (size_t i = 0; i < lsz; ++i) {
            int carry = 0;
            size_t j;
            for (j = 0; j < rsz; ++j) {
                long long cur = out._v[i + j] + _v[i] * 1ll * obj._v[j] + carry;
                out._v[i + j] = int(cur % base);
                carry = int(cur / base);
            }
            if (carry) {
                out._v[i + j] = out._v[i + j] + carry;;
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

        char s[10] = { '\0' };
        sprintf(s, "%d", _v.back());

        string res;
        res.reserve(_v.size() * 9 + 1);
        res += s;

        if (_v.size() > 2) {
            for (size_t i = _v.size() - 2; i > 0; --i) {
                sprintf(s, "%09d", _v[i]);
                res += s;
            }
        }
        if (_v.size() >= 2) {
            sprintf(s, "%09d", _v.front());
            res += s;
        }
        return res;
    }
};


BigNum Fib(unsigned n) {
    BigNum p0 = 0, p1 = 1,
           p2 = 1, p3 = 1;

    BigNum a0 = 1, a1 = 0,
           a2 = 0, a3 = 1;

    BigNum t0, t1, t2, t3;
    BigNum f0, f1, f2, f3;

    --n;

    while (n) {
        #pragma omp parallel
        {
            if (n & 1) {
                #pragma omp sections
                {
                    #pragma omp section
                    t0 = a0 * p0 + a1 * p2;

                    #pragma omp section
                    t1 = a0 * p1 + a1 * p3;

                    #pragma omp section
                    t2 = a2 * p0 + a3 * p2;

                    #pragma omp section
                    t3 = a2 * p1 + a3 * p3;
                }

                #pragma omp single
                {
                    a0 = move(t0);
                    a1 = move(t1);
                    a2 = move(t2);
                    a3 = move(t3); 
                }
            }

            #pragma omp sections
            {
                #pragma omp section
                f0 = p0 * p0 + p1 * p2;

                #pragma omp section
                f1 = p1 * (p0 + p3);

                #pragma omp section
                f2 = p2 * (p0 + p3);

                #pragma omp section
                f3 = p1 * p2 + p3 * p3;
            }

            #pragma omp single
            {
                p0 = move(f0);
                p1 = move(f1);
                p3 = move(f3);
                p2 = move(f2);
            }
        }

        n >>= 1;
    }

    return a3;
}


int main() {
    constexpr int N = int(3e6);
    freopen("fib.out", "w", stdout);

    cerr << "Calc fibonacci(" << N << ")...";
    auto start = std::chrono::high_resolution_clock::now();

    BigNum F = Fib(N);

    auto stop = std::chrono::high_resolution_clock::now();
    cerr << "\nDone!\n";

    cout << "Calculation time: " << (stop - start).count() * 1e-9 << " sec\n";
    cout << "Fib(" << N << ") = " << F.get_str() << '\n';

    return 0;
}

