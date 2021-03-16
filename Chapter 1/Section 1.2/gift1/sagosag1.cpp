
/*
ID: sagosag1
TASK: gift1
LANG: C++
*/

#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    int N; fin >> N;

    vector<string> enumerate(N);
    map<string, int> data;

    for (int i = 0; i < N; ++i) {
        string in; fin >> in;
        enumerate[i] = in;
        data.insert(pair<string, int>(in, 0));
    }

    while (N--) {
        string giver; int money, count;
        fin >> giver >> money >> count;
        if (count == 0) {
            continue;
        }
        if (money == 0) {
            while (count--) {
                string skip; fin >> skip;
            }
            continue;
        }
        data[giver] -= money - (money % count);
        int gift = money / count;
        for (int j = 0; j < count; ++j) {
            string lucky; fin >> lucky;
            data[lucky] += gift;
        }
    }

    for (const auto& it : enumerate) {
        fout << it << ' ' << data[it] << '\n';
    }

    return 0;
}

