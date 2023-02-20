#include<bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
bool used[1001];

void dfs(int u) {
    used[u] = true;
    for(int t : ke[u]) {
        if(used[t] == false) {
            dfs(t);
        }
    }
}
void inp() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x; cin >> x;
            if(x == 1) {
                ke[i].push_back(j);
                ke[j].push_back(i);
            }
        }
    }
    memset(used, false, sizeof(used));
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(used[i] == false) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}
int main() {
    inp();
}     