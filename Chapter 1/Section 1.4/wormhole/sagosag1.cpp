
/*
ID: sagosag1
TASK: wormhole
LANG: C++
*/

#include <fstream>

#define MAX_N (12)

using namespace std;

struct coord {
    int x, y;
};
struct edge {
    int v;
    coord crd;
};
using graph = edge[MAX_N];

int N;
coord wormholes[MAX_N];

int main() {
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    fin >> N;
    for (int i = 0; i < N; ++i) {
        fin >> wormholes[i].x >> wormholes[i].y;
    }



    return 0;
}

