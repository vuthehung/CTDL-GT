#include<bits/stdc++.h>
using namespace std;
int n, m, s;
int X[1001];
vector<int> ke[1001];
vector<int> cycle;
bool visited[1001];
void init() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void Try(int u) { // cach 1
    for(int x : ke[u]) {
        if(cycle.size() == n && x == s) {
            for(int x : cycle) cout << x << " ";
            cout << s  << endl;
        }
        else if(!visited[x]) {
            cycle.push_back(x);
            visited[x] = true;
            Try(x);
            // quay lui
            cycle.pop_back();
            visited[x] = false;
        }
    }
}
void hmt(int k) { // cach 2
    for(int y : ke[X[k - 1]]) {
        if(k == n + 1) {
            for(int i = 1; i < k; i++) {
                cout << X[i] << " ";
            }
            cout << s << endl;
            return;
        }else if(!visited[y]) {
            X[k] = y;
            visited[y] = true;
            hmt(k + 1);
            visited[y] = false;
        }
    }
}
int main(){ 
    init();
    cin >> s;
    //X[1] = s; // cach 2
    cycle.push_back(s); // cach 1
    visited[s] = true;
    Try(s); // cach 1
    //hmt(2);// cach 2
}


