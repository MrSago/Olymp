
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

using namespace std;

using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using Graph = vector<vi>;

Graph g;
bool directed;
vc color;
vb used;

bool isCycleD(int v) {
    color[v] = 1;
    for (int& u : g[v]) {
        if (color[u] == 0) {
            if (isCycleD(u)) {
                return true;
            }
        } else if (color[u] == 1) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool isCycleU(int v, int p = -1) {
    used[v] = true;
    for (int& u : g[v]) {
        if (!used[u]) {
            isCycleU(u, v);
        } else if (u != p) {
            return true;
        }
    }
    return false;
}

inline void scanGraph() {
    int N; cin >> N >> directed; cin.ignore();
    g.resize(N);
    for (vi& u : g) {
        stringstream ss; string s;
        getline(cin, s);
        ss << s;
        while (!ss.eof()) {
            int v; ss >> v;
            if (v <= 0) {
                break;
            }
            u.push_back(v - 1);
        }
    }
}

inline void printGraph() {
    cout << "Graph: " << (directed ? "directed" : "undirected") << '\n';
    for (int i = 0; i < (int)g.size(); ++i) {
        cout << '[' << i + 1 << "] => {";
        for (auto& j : g[i]) {
            cout << ' ' << j + 1;
        }
        cout << " }\n";
    }
}

inline bool checkCycle() {
    if (directed) {
        color.assign(g.size(), 0);
        for (int i = 0; i < (int)g.size(); ++i) {
            if (isCycleD(i)) {
                return true;
            }
        }
    } else {
        used.assign(g.size(), false);
        for (int i = 0; i < (int)g.size(); ++i) {
            if (!used[i]) {
                if (isCycleU(i)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    assert(freopen("cycle.in", "r", stdin));
    assert(freopen("cycle.out", "w", stdout));

    scanGraph();

    printGraph();

    if (checkCycle()) {
        cout << "Cyclic\n";
    } else {
        cout << "Acyclic\n";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

