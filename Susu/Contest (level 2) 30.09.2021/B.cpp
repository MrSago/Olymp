
/*
    author: MrS4g0
    created: 02.10.2021 10:52:06
*/

#include <iostream>
#include <map>

using namespace std;


class Bug {
private:
    map<size_t,size_t> val;
    size_t arr[100001];
    size_t* l = arr;
    size_t* r = arr;
    size_t sum = 0;

public:
    void Add(size_t a) {
        ++val[a];
        sum += a;
        *r = a;
        ++r;
    }
    void Del() {
        --val[*l];
        sum -= *l;
        ++l;
    }
    size_t Avarage() {
        return sum % (r - l) == 0 ? val[sum / (r - l)] : 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Bug bug;

    int n; scanf("%d", &n); getchar();

    for (int i = 0; i < n; ++i) {
        int c = getchar();

        switch (c) {
            case '+':
                getchar();
                size_t s;
                scanf("%llu", &s);
                bug.Add(s);
            break;
            
            case '-':
                bug.Del();
            break;

            case '?':
                printf("%llu\n", bug.Avarage());
            break;
        }

        getchar();
    }

    return 0;
}

