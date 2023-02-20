#include<bits/stdc++.h>
using namespace std;

// int n, m;
// bool used[1001];
// vector<int> ke[1001];

// // dung phuong phap de quy
// void dfs(int u) {
//     cout << u << " ";
//     used[u] = true;
//     for(int v : ke[u]) {
//         if(used[v] == false) {
//             dfs(v);
//         }
//     }
// }
// int main() {
//     cin >> n >> m;
//     for(int i = 0; i < m; i++) {
//         int x, y;
//         cin >> x >> y;
//         ke[x].push_back(y);
//         ke[y].push_back(x);
//     }
//     memset(used, false, sizeof(used));
//     dfs(1);
// }

// // input cho bang ma tran ke.
int n;
int a[1001][1001];
bool chuaxet[1001];
void dfs(int u) {
    cout << u << " ";
    chuaxet[u] = false;
    for(int i = 1; i <= n; i++) {
        if(a[u][i] == 1 && chuaxet[i]) {
            dfs(i);
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    memset(chuaxet, true, sizeof(chuaxet));
    dfs(1);
}


// dung ngan xep stack
// int n;
// int a[1001][1001];
// bool used[1001];
// void dfs(int u) {
//     stack<int> s;
//     s.push(u);
//     cout << u << " ";
//     used[u] = true;
//     while(!s.empty()) {
//         int s1 = s.top();
//         s.pop();
//         for(int i = 1; i <= n; i++) {
//             if(used[i] == false && a[s1][i] == 1) {
//                 cout << i << " ";
//                 used[i] = true;
//                 s.push(s1);
//                 s.push(i);
//                 break;
//             }
//         }
//     }
// }
// int main() {
//     cin >> n;
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= n; j++) {
//             cin >> a[i][j];
//         }
//     }
//     memset(used, false, sizeof(used));
//     dfs(1);
// }