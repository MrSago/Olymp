
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

using namespace std;

using vc = vector<char>;
using vb = vector<bool>;
using vi = vector<int>;
using Graph = vector<vi>;

Graph g;
bool org;
vc color;
vb used;

bool isCycleO(int v) {
    color[v] = 1;
    for (int& u : g[v]) {
        if (color[u] == 0) {
            if (isCycleO(u)) {
                return true;
            }
        } else if (color[u] == 1) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool isCycleN(int v, int p = -1) {
    used[v] = true;
    for (int& u : g[v]) {
        if (!used[u]) {
            isCycleN(u, v);
        } else if (u != p) {
            return true;
        }
    }
    return false;
}

inline void scanGraph() {
    int N; cin >> N >> org; cin.ignore();
    g.resize(N);
    for (auto& u : g) {
        stringstream ss; string s;
        getline(cin, s);
        ss << s;
        while (!ss.eof()) {
            int v; ss >> v;
            if (v < 0) {
                break;
            }
            u.push_back(v - 1);
        }
    }
}

inline void printGraph() {
    cout << "Orgraph: " << (org ? "true" : "false") << '\n';
    for (int i = 0; i < (int)g.size(); ++i) {
        cout << '[' << i + 1 << "] => {";
        for (auto& j : g[i]) {
            cout << ' ' << j + 1;
        }
        cout << " }\n";
    }
}

inline bool findCycle() {
    if (org) {
        color.assign(g.size(), 0);
        for (int i = 0; i < (int)g.size(); ++i) {
            if (isCycleO(i)) {
                return true;
            }
        }
        return false;
    } else {
        used.assign(g.size(), false);
        for (int i = 0; i < (int)g.size(); ++i) {
            if (!used[i]) {
                if (isCycleN(i)) {
                    return true;
                }
            }
        }
        return false;
    }
}

int main() {
    assert(freopen("cycle.in", "r", stdin));
    assert(freopen("cycle.out", "w", stdout));

    scanGraph();

    printGraph();

    if (findCycle()) {
        cout << "Cyclic\n";
    } else {
        cout << "Acyclic\n";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

