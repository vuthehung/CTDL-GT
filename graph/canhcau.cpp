// canh e la canh cau neu loai bo e lam tang thanh phan lien thong

#include<bits/stdc++.h>
using namespace std;
int n; 
vector<int> ke[1001];
bool used[1001];
vector<pair<int, int>> dscanh;
void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x; cin >> x;
            if(x == 1) {
                ke[i].push_back(j);
                ke[j].push_back(i);
            }
            if(x == 1 && i < j) {
                dscanh.push_back({i, j});
            }
        }
    }
}
void dfs(int u){
    used[u] = true;
    for(int t : ke[u]) {
        if(!used[t]) dfs(t);
    }
}
void dfs2(int u, int s, int t) {
    used[u] = true;
    for(int v : ke[u]) {
        if((u == s && v == t) || (u == t && v == s)) continue; // loai bo dinh s, t
        if(!used[v]) dfs2(v, s, t);
    }
}
void canhcau() {
    int tplt = 0;
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            dfs(i);
            tplt++;
        }
    }
    for(auto it : dscanh) {
        int x = it.first, y = it.second;
        // loai bo dinh(x, y) ra khoi do thi
        memset(used, false, sizeof(used));
        int dem = 0;
        for(int j = 1; j <= n; j++) {
            if(!used[j]) {
                dem++;
                dfs2(j, x, y);
            }
        }
        if(dem > tplt) cout << x << " " << y << endl;
    }
}
int main() {
    init();
    canhcau();
}