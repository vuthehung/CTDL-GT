#include<bits/stdc++.h>
using namespace std;
int n, a[100][100], ok;
char c[100];
void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}
void back_track(int i, int j, int k) {
    if(i == n && j == n) {
        for(int i = 1; i < k; i++) {
            cout << c[i];
        }
        cout << " ";
        ok = 1;
        return;
    }
    if(i + 1 <= n && a[i + 1][j] == 1) {
        c[k] = 'D';
        a[i + 1][j] = 0;
        back_track(i + 1, j, k +1);
        a[i + 1][j] = 1;
    }
    if(j + 1 <= n && a[i][j + 1] == 1) {
        c[k] = 'R';
        a[i][j + 1] = 0;
        back_track(i, j + 1, k + 1);
        a[i][j + 1] = 1;
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        init();
        ok = 0;
        if(a[1][1] && a[n][n]) {
            back_track(1, 1, 1);
        }
        if(ok) cout << endl;
        else cout << "-1\n";
    }
}