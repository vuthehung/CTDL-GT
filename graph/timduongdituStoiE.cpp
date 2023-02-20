#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
bool used1[1001];
bool used2[1001];
int parent1[1001];
int parent2[1001];
int n, s, e;
int ok;
vector<int> v1;
vector<int> v2;
void init() {
    vector<pair<int, int>> v;
    cin >> n >> s >> e;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x; cin >> x;
            if(x == 1) {
                ke[i].push_back(j);
                ke[j].push_back(i);
            }
        }
    }
}
void dfs(int u) {
    used1[u] = true;
    for(int t : ke[u]) {
        if(used1[t] == false) {
            parent1[t] = u;
            dfs(t);
        }
    }
}
void bfs(int u) {
    queue<int> q;
    q.push(u);
    used2[u] = true;
    while(!q.empty()) {
        s = q.front();
        q.pop();
        for(int t : ke[s]) {
            if(used2[t] == false) {
                parent2[t] = s;
                q.push(t);
                used2[t] = true;
            }
        }
    }
}
void outDFS(int s, int e) {
    memset(used1, false, sizeof(used1));
    dfs(s);
    if(used1[e] == false) {
        ok = 0;
    }else {
        ok = 1;
        while(e != s) {
            v1.push_back(e);
            e = parent1[e];
        }
        v1.push_back(s);
        reverse(v1.begin(), v1.end());
    }
}
void outBFS(int s, int e) {
    memset(used2, false, sizeof(used2));
    bfs(s);
    if(used2[e] == false) {
        ok = 0;
    }else {
        ok = 1;
        while(e != s) {
            v2.push_back(e);
            e = parent2[e];
        }
        v2.push_back(s);
        reverse(v2.begin(), v2.end());
    }
}
int main() {
    init();
    outDFS(s, e);
    outBFS(s, e);
    if(ok == 0) {
        cout << "no path";
    }else {
        cout << "DFS path: ";
        for(int x : v1) cout << x << " ";
        cout << endl;
        cout << "BFS path: ";
        for(int x : v2) cout << x << " ";
    }
}
