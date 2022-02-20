
/*
    author: MrS4g0
    created: 18.02.2022 22:08:38
*/

#include <bits/stdc++.h>
using namespace std;


int Eval(string& l, char op, string& r) {
    int a = stoi(l);
    int b = stoi(r);

    switch (op) {
        case '*':
            return a * b;
        case '+':
            return a + b;
        case '-':
            return a - b;
        default:
            return 0;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<string> st;
    string s;
    getline(cin, s);

    for (auto& c : s) {
        if (isdigit(c)) {
            st.push(string(1, c));
        } else if (c == '+' || c == '-' || c == '*') {
            string r = st.top();
            st.pop();
            string l = st.top();
            st.pop();
            int result = Eval(l, c, r);
            st.push(to_string(result));
        }
    }

    cout << st.top() << '\n';

    return 0;
}

