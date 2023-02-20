#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> ke[1001];
bool used[1001];
void init() {
    cin >> n;
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
    used[u] = true;
    for(int t : ke[u]) {
        if(used[t] == false) {
            dfs(t);
        }
    }
}
void dinhtru() { // dinh u dinh tru neu loai bo u va cac canh noi voi u lam tang thanh phan lien thong
    int tplt = 0;
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++) {
        if(used[i] == false) {
            dfs(i);
            tplt++; // dem so thanh phan lien thong
        }
    }
    for(int i = 1; i <= n; i++) {
        // loai bo dinh i khoi do thi
        memset(used, false, sizeof(used));
        used[i] = true;
        int dem = 0;// dem so thanh phan lien thong sau khi bo dinh i
        for(int j = 1; j <= n; j++) {
            if(used[j] == false) {
                dem++;
                dfs(j);
            }
        }
        if(dem > tplt) {
            cout << i << " ";
        }
    }
}
int main() {
    init();
    dinhtru();
}