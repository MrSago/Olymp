
/*
ID: sagosag1
TASK: test
LANG: C++
*/

#include <fstream>

using namespace std;

int main() {
    ifstream fin("test.in");
    ofstream fout("test.out");

    int a, b; fin >> a >> b;
    fout << a + b << '\n';

    return 0;
}

