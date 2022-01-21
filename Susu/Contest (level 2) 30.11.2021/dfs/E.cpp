
#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }

constexpr int MOD = int(1e9) + 7;
constexpr int NMOD = 998244353;


int inserts[101] = { 0 };
vector<int> g[101];
vector<bool> used(101);
vector<int> answer;
vector<int> cl(101);
map <string, int> names;
map <int, string> indexes;
int N;

void dfs (int v) {
	cl[v] = 1;
    used[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to] && cl[to] == 0) {
			dfs(to);
		}
		else if (cl[to] == 1) {
			cout << "IMPOSSIBLE";
            exit(0);
		}
	}
	cl[v] = 2;
    answer.push_back(v);
}

void topological_sort() {
	for (int i=0; i<N; ++i)
		used[i] = false;
	answer.clear();
	for (int i=0; i<N; ++i)
		if (!used[i])
			dfs (i);
    reverse(answer.begin(), answer.end());
}

int main() {
    scanf("%d", &N); getchar();
    int bogatirIndex = 0;
    char line[513];
    char* p;

    for (int i = 0; i < N; i++){
        fgets(line, 512, stdin);
        p = strtok(line, " \n");
        string v = p;
        if (!names.count(v)) {
            names[v] = bogatirIndex;
            indexes[bogatirIndex++] = v;
        }

        p = strtok(NULL, " \n");
        while (p != NULL) {
            string bogatir = p;
            if (!names.count(bogatir)){
                names[bogatir] = bogatirIndex;
                indexes[bogatirIndex++] = bogatir;
            }
            g[names[v]].push_back(names[bogatir]);
            inserts[names[bogatir]] = 1;
            p = strtok(NULL, " \n");
        }
    }

    topological_sort();

    for (int i = 0; i < N; i++){
        cout << indexes[answer[i]] << " ";
    }
    cout << nl;

    return 0;
}

