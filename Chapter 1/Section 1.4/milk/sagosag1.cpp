
/*
ID: sagosag1
TASK: milk
LANG: C++
*/

#include <fstream>

using namespace std;

struct farm {
    int price;
    int amount;
};

inline int cmp(const void* a, const void* b) {
    return ((farm*)a)->price - ((farm*)b)->price;
}

farm data[5000];

int main() {
    ifstream fin("milk.in");
    ofstream fout("milk.out");

    int N, M;
    fin >> N >> M;
    for (int i = 0; i < M; ++i) {
        farm* ptr = data + i;
        fin >> ptr->price >> ptr->amount;
    }

    qsort(data, M, sizeof(farm), cmp);

    int cost = 0;
    for (int i = 0; i < M; ++i) {
        farm* ptr = data + i;
        N -= ptr->amount;
        if (N < 0) {
            cost += ptr->price * (ptr->amount + N);
            break;
        }
        cost += ptr->price * ptr->amount;
    }

    fout << cost << '\n';

    return 0;
}

