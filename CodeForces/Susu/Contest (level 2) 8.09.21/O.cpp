
/*
    author: MrS4g0
    created: 11.09.2021 20:59:29
*/

#include <iostream>
using namespace std;


int main() {
    size_t N; cin >> N;
    size_t res = 0;
    for (size_t i = 1; i <= N; ++i) {
        res += i;
    }
    printf("%.2Lf", (long double)res);

    return 0;
}

