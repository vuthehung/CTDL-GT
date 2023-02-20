#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int n, m;
int cnt = 0;
void init() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cnt = 0;
}
void b_t(int i, int j) {
    if(i == n && j == m) {
        cnt++;
        return;
    }
    if(i + 1 <= n) {
        b_t(i + 1, j);
    }
    if(j + 1 <= m) {
        b_t(i, j + 1);
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        init();
        b_t(1, 1);
        cout << cnt << endl;
    }
}