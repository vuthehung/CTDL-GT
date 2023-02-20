#include<bits/stdc++.h>
using namespace std;
set<int> ke[1001];
int n, m, in[1001], out[1001];
void init() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        ke[x].insert(y);
        in[y]++; out[x]++;
    }
}
void euler_cycle(int u) {  // chu trinh euler
    for(int i = 1; i <= n; i++) {
        if(in[i] != out[i]) {
            cout << "ko co chu trinh euler";
            return;
        }
    }
    stack<int> st;
    st.push(u);
    vector<int> cycle;
    while(!st.empty()) {
        int u = st.top();
        if(ke[u].size() != 0) {
            int v = *ke[u].begin();        
            st.push(v);
            ke[u].erase(v);
            ke[v].erase(u);
        }else {
            st.pop();
            cycle.push_back(u);
        }
    }
    reverse(cycle.begin(), cycle.end());
    for(int x : cycle) cout << x << " ";
}
void euler_path() { // duong di euler
    int cnt = 0, u = -1, v = -1;
    for(int i = 1; i <= n; i++) {
        if(in[i] != out[i]) {
            cnt++;
            if(in[i] == out[i] + 1) v = i;
            if(out[i] == in[i] + 1) u = i;
        }
    }
    if(cnt != 2 || u == - 1 || v == -1) {
        cout << "ko co duong di euler";
        return;
    }
    stack<int> st;
    st.push(u);
    vector<int> path;
    while(!st.empty()) {
        int u = st.top();
        if(ke[u].size() != 0) {
            int v = *ke[u].begin();
            st.push(v);
            ke[u].erase(v);
            ke[v].erase(u);
        }else {
            st.pop();
            path.push_back(u);
        }
    }
    reverse(path.begin(), path.end());
    for(int x : path) cout << x << " ";
}
int main() {
    init();
    euler_cycle(5);
    cout << endl;
    euler_path();
}
