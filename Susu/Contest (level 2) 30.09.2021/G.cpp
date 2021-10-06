
/*
    author: MrS4g0
    created: 06.10.2021 22:01:37
*/

#include <bits/stdc++.h>
using namespace std;

#define nl ('\n')

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;
using vull = vector<ull>;

using pii = pair<int,int>;
using graph = vector<vi>;

template <typename T = int>
inline T nxt() { T x; cin >> x; return x; }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> st;
    st.push(0);

    int n = nxt(), ans = -1;

    for (int i = 0, tmp; i < n; ++i) {
        tmp = nxt();
        while (st.top() > tmp) {
            st.pop();
            ++ans;
        }
        if (st.top() < tmp) {
            st.push(tmp);
        }
    }

    cout << ans + (int)st.size() << "\n";
    return 0;
}

