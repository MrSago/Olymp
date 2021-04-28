
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int good1, bad1, good2, bad2;
    fin >> good1 >> bad1 >> good2 >> bad2;

    if (
        good1 - min(bad2, good1) == 0 ||
        good2 - min(bad1, good2) == 0
    ) {
        fout << "no\n";
    } else {
        fout << "yes\n";
    }

    return 0;
}

