/*
ID: deadly51
TASK: skidesign
LANG: C++
*/
#include <fstream>
#include <limits.h>
using namespace std;
#define MAX_N 1000
#define MAX_DIF 17


int main(void) {
    int N, HILLS[MAX_N];
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    fin >> N;
    for (int i=0; i<N; i++)
        fin >> HILLS[i];
    fin.close();

    int answer = INT_MAX;
    for (int i=0; i<=83; i++) {
        int current = 0;
        for (int j=0; j<N; j++) {
            int t;
            if (HILLS[j] < i)
                t = i - HILLS[j];
            else if (HILLS[j] > i + MAX_DIF)
                t = HILLS[j] - (i + MAX_DIF);
            else
                t = 0;
            current += t*t;
        }
        answer = min(answer, current);
    }

    fout << answer << '\n';
    fout.close();
    return 0;
}

