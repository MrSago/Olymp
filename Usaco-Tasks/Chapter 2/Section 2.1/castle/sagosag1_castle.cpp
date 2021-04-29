
/*
ID: sagosag1
TASK: castle
LANG: C++
*/

// deadly51 and sagosag1(MrS4g0) collab


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
    for (int i : g[v]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

inline void find_comps() {
    for (int i = 0; i < (int)g.size(); i++) {
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
        for (char c : paths) {
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


#define DBG
#ifdef DBG
    #include <iostream>
    #include <chrono>
    #define START_TIME auto start = std::chrono::high_resolution_clock::now();
    #define PRINT_TIME auto stop = std::chrono::high_resolution_clock::now(); \
                       std::cout << "time: " << (stop - start).count() * 1e-6 << " ms\n";
    inline void printGraph() {
        std::cout << "graph:\n";
        for (int i = 0; i < (int)g.size(); ++i) {
            std::cout << '[' << i << "] => {";
            for (int j : g[i]) {
                std::cout << ' ' << j;
            }
            std::cout << " }\n";
        }
    }
    inline void printComp() {
        std::cout << "components:\n";
        for (auto& it : components) {
            std::cout << '[' << it.size() << "] => { ";
            for (int j : it) {
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
                for (char k : sp) {
                    switch (k) {
                        case 'D':
                            field[i + 1][j] = ' ';
                            break;
                        case 'R':
                            field[i][j + 1] = ' ';
                            break;
                        case 'U':
                            field[i - 1][j] = ' ';
                            break;
                        case 'L':
                            field[i][j - 1] = ' ';
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
            for (char j : it) {
                std::cout << j << ' ';
            }
            std::cout << "#\n";
        }
        for (int i = 0; i <= M + M; ++i) {
            std::cout << "# ";
        }
        cout << '\n';
    }
#else //if !DBG
    #define START_TIME do{}while(0);
    #define PRINT_TIME do{}while(0);
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
        for (char c : paths) {
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
    pair<int,int> wall;
    for (int i = 0; i < (int)components.size(); ++i) {
        for (auto j : components[i]) {
            int ver[] = { 
                (j - 1) % M == M - 1 ? -1 : j - 1, 
                (j + 1) % M == 0     ? -1 : j + 1, 
                j - M < 0            ? -1 : j - M, 
                j + M > N - 1        ? -1 : j + M
            };
            for (auto k = components.begin() + i + 1; k != components.end(); ++k) {
                for (int z : ver) {
                    if (z != -1 && find((*k).begin(), (*k).end(), z) != (*k).end()) {
                        int sz = components[i].size() + (*k).size();
                        if (sz >= res) {
                            res = sz;
                            wall = { max(j, wall.first), min(z, wall.second) };
                        }
                    }
                }
            }
        }
    }

    char dir = 'E';
    int tmp = wall.first - wall.second;
    if (tmp == 1) {
        dir = 'W';
    } else if (tmp == -1) {
        dir = 'E';
    } else if (tmp == M - 1) {
        dir = 'N';
    } else if (tmp == 1 - M) {
        dir = 'S';
    }

    fout << components.size() << '\n' << 
            components[0].size() << '\n' << 
            res << '\n' << 
            wall.first / M + 1 << ' ' << wall.first % M + 1 << ' ' << dir << '\n';

    PRINT_TIME

    printGraph();
    printComp();
    castleVis(fin);

    return 0;
}








// 27
// 55
// 85
// 11_11_E
// ---- your output ---------
// 27
// 55
// 85
// 8_11_E

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
// #       #       #       #       #       #       #           #
// # # # # #   #   #   #   #   #   #   #   #   #   # # #   #   #
// #           #       #       #       #       #       #       #
// #   # # # # # # # # # # # # # # # # # # # # # # #   #   #   #
// #   #   #                               #       #   #       #
// # # #   # # # # # # # # # # # # # # # # # # #   #   #   #   #
// #       #                                   #   #   #       #
// # # #   #   # # # # # # # # # # # # # # #   #   # # #   #   #
// #   #   #   #   #                   #   #   #   #   #       #
// #   # # #   #   # # # # #   # # # # #   #   # # #   # # # # #
// #       #   #           #   #           #       #           #
// #   # # #   #   # # # # #   # # # # #   # # #   #   # # #   #
// #   #   #   #   #                   #   #       #           #
// # # #   #   #   #   # # # # # # #   #   #   # # # # # # # # #
// #       #   #   #   #           #   #   #-->#               #
// # # #   #   # # #   #   # # #   #   # # #   #   # # # # #   #
// #   #   #           #           #           #   #           #
// #   # # #   # # #   #   # # #   #   # # #   #   #   # # # # #
// #       #   #   #   #           #   #   #   #   #           #
// #   # # #   #   #   # # # # # # #   #   #   #   # # # # #   #
// #   #   #   #   #                   #   #   #   #           #
// # # #   # # #   # # # # #   # # # # # # # # #   #   # # # # #
// #   #   #   #           #   #       #       #   #           #
// #   #   # # # # # # # # #   # # # # # # # # #   # # # # #   #
// #   #   #   #   #                   #   #       #           #
// #   # # #   #   # # # # # # # # # # #   #   # # #   # # # # #
// #   #   #   #   #           #           #                   #
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

