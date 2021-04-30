
/*
ID: sagosag1
TASK: castle
LANG: C++
*/

// deadly51(@ggodos) and sagosag1(@MrSago) collab


#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using graph = vector<vi>;

int M, N;
graph g;
vb visited;
graph components;
vi comp;

void dfs (int v) {
    visited[v] = true;
    comp.push_back(v);
    for (auto& i : g[v]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

inline void find_comps() {
    for (int i = 0; i < (int)g.size(); ++i) {
        if (!visited[i]) {
            comp.clear();
            dfs(i);
            components.push_back(comp);
        }
    }
    comp.clear();
}

inline vc getPaths(int number) {
    const char paths[4] = {'D', 'R', 'U', 'L'};
    vc ret;
    if (number == 0) {
        for (auto& c : paths) {
            ret.push_back(c);
        }
        return ret;
    }
    bool walls[4] = { false };
    if (number >= 8) {
        walls[0] = true;
        number -= 8;
    }
    if (number >= 4) {
        walls[1] = true;
        number -= 4;
    }
    if (number >= 2) {
        walls[2] = true;
        number -= 2;
    }
    if (number == 1) {
        walls[3] = true;
    }
    for (int i = 0; i < 4; ++i) {
        if (!walls[i]) {
            ret.push_back(paths[i]);
        }
    }
    return ret;
}


//#define DBG
#ifdef DBG
    #include <iostream>
    #include <chrono>
    #include <cassert>
    #define START_TIME auto start = std::chrono::high_resolution_clock::now();
    #define STOP_TIME auto stop = std::chrono::high_resolution_clock::now();
    #define PRINT_TIME std::cout << "time: " << (stop - start).count() * 1e-6 << " ms\n";
    inline void debugInFile() {
        assert(freopen("debug.out", "w", stdout));
    }
    inline void printGraph() {
        std::cout << "graph:\n";
        for (int i = 0; i < (int)g.size(); ++i) {
            std::cout << '[' << i << "] => {";
            for (auto& j : g[i]) {
                std::cout << ' ' << j;
            }
            std::cout << " }\n";
        }
    }
    inline void printComp() {
        std::cout << "components:\n";
        for (auto& it : components) {
            std::cout << '[' << it.size() << "] => { ";
            for (auto& j : it) {
                std::cout << j << " ";
            }
            std::cout << "}\n";
        }
    }
    inline void castleVis(std::ifstream& fin) {
        fin.close();
        fin.clear();
        fin.open("castle.in");
        int tmp; fin >> tmp >> tmp;
        std::vector<std::vector<char>> field(N + N - 1, std::vector<char>(M + M - 1, '#'));
        for (int i = 0; i < N + N - 1; i += 2) {
            for (int j = 0; j < M + M - 1; j += 2) {
                field[i][j] = ' ';
                int f; fin >> f;
                std::vector<char> sp = getPaths(f);
                for (auto& k : sp) {
                    switch (k) {
                        case 'L':
                            field[i][j - 1] = ' ';
                            break;
                        case 'R':
                            field[i][j + 1] = ' ';
                            break;
                        case 'U':
                            field[i - 1][j] = ' ';
                            break;
                        case 'D':
                            field[i + 1][j] = ' ';
                            break;
                    }
                }
            }
        }
        std::cout << "castle visualization:\n";
        for (int i = 0; i <= M + M; ++i) {
            std::cout << "# ";
        }
        std::cout << "\n";
        for (auto& it : field) {
            std::cout << "# ";
            for (auto& j : it) {
                std::cout << j << ' ';
            }
            std::cout << "#\n";
        }
        for (int i = 0; i <= M + M; ++i) {
            std::cout << "# ";
        }
        std::cout << '\n';
    }
#else //if !DBG
    #define START_TIME do{}while(0);
    #define STOP_TIME do{}while(0);
    #define PRINT_TIME do{}while(0);
    inline void debugInFile() {}
    inline void printGraph() {}
    inline void printComp() {}
    inline void castleVis(std::ifstream&) {}
#endif //DBG


int main() {
    START_TIME
    ios::sync_with_stdio(false);
    ifstream fin("castle.in");
    ofstream fout("castle.out");

    fin >> M >> N;
    g.resize(N * M);
    visited.assign(N * M, false);

    for (int i = 0; i < (int)g.size(); ++i) {
        int n; fin >> n;
        vc paths = getPaths(n);
        for (auto& c : paths) {
            switch (c) {
                case 'L':
                    g[i].push_back(i - 1);
                    break;
                case 'R':
                    g[i].push_back(i + 1);
                    break;
                case 'U':
                    g[i].push_back(i - M);
                    break;
                case 'D':
                    g[i].push_back(i + M);
                    break;
            }
        }
    }

    find_comps();
    sort(
        components.begin(), components.end(),
        [](const vi& x, const vi& y) {
            return x.size() > y.size();
        }
    );

    int res = 0;
    pair<int,int> connection;
    for (int i = 0; i < (int)components.size() - 1; ++i) {
        for (int j = i + 1; j < (int)components.size(); ++j) {
            for (auto& k : components[i]) {
                int v[] = {
                    (k - 1) % M == M - 1 ? -1 : k - 1, //L
                    (k + 1) % M == 0     ? -1 : k + 1, //R
                    k < M                ? -1 : k - M, //U
                    k >= M * (N - 1)     ? -1 : k + M  //D
                };
                for (auto& s : v) {
                    if (s != -1 && find(components[j].begin(), components[j].end(), s) != components[j].end()) {
                        int sz = (int)components[i].size() + (int)components[j].size();
                        if (sz > res) {
                            res = sz;
                            connection = { k, s };
                        } else if (sz == res) {
                            if (k % M < connection.first % M) {
                                connection = { k, s };
                            } else if ((k % M == connection.first % M) && (k / M > connection.first / M)) {
                                connection = { k, s };
                            }
                        }
                        if (connection.first - connection.second == -M) {
                            swap(connection.first, connection.second);
                        }
                    }
                }
            }
        }
    }

    char dir;
    int tmp = connection.first - connection.second;
    if (tmp == 1) {
        dir = 'W'; //L
    } else if (tmp == -1) {
        dir = 'E'; //R
    } else if (tmp == M) {
        dir = 'N'; //U
    } else {
        dir = 'S'; //D
    }

    fout << components.size() << '\n'
         << components[0].size() << '\n'
         << res << '\n'
         << connection.first / M + 1 << ' ' << connection.first % M + 1 << ' ' << dir << '\n';

    STOP_TIME
    debugInFile();
    PRINT_TIME
    printGraph();
    printComp();
    castleVis(fin);

    return 0;
}

