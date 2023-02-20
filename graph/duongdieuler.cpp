// khong khac chu trinh la may

#include<bits/stdc++.h>
using namespace std;
set<int> ke[1001];
int a[1001][1001];
int n, m, degree[1001];
void init() {
    // cin >> n >> m;
    // for(int i = 1; i <= m; i++) {
    //     int x, y; cin >> x >> y;
    //     ke[x].insert(y);
    //     ke[y].insert(x);
    //     degree[x]++; degree[y]++;
    // }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] && a[j][i]) {
                ke[i].insert(j); ke[j].insert(i);
                degree[i]++; degree[j]++;
            }
        }
    }
}
void euler_path() {
    int cnt = 0, u = -1, v = -1;
    for(int i = 1; i <= n; i++) {
        if(degree[i] % 2 == 1) {
            ++cnt;
            if(u == -1) u = i;
            else if(v == -1) v = i;
        }
    }
    if(cnt != 2) {
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
    for(int x : path) cout << x << " ";
}
int main() {
    init();
    euler_path();
}