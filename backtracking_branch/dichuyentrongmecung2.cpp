#include<bits/stdc++.h>
using namespace std;
int n, a[100][100], ok, cnt;
char c[100];
vector<vector<char>> v;
void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cnt = 0;
    ok = 0;
}
void b_t(int i, int j, int k) {
    if(i == n && j == n) {
        vector<char> x;
        for(int l = 1; l < k; l++) {
            x.push_back(c[l]);
        }
        v.push_back(x);
        cnt++;
        ok = 1;
        return;
    }
    if(i + 1 <= n && a[i + 1][j] == 1) {
        c[k] = 'D';
        a[i + 1][j] = 0;
        b_t(i + 1, j, k + 1);
        a[i + 1][j] = 1;
    }
    if(j - 1 <= n && a[i][j - 1] == 1) {
        c[k] = 'L';
        a[i][j - 1] = 0;
        b_t(i, j - 1, k + 1);
        a[i][j - 1] = 1;
    }
    if(j + 1 <= n && a[i][j + 1] == 1) {
        c[k] = 'R';
        a[i][j + 1] = 0;
        b_t(i, j + 1, k + 1);
        a[i][j + 1] = 1;
    }
    if(i - 1 <= n && a[i - 1][j] == 1) {
        c[k] = 'U';
        a[i - 1][j] = 0;
        b_t(i - 1, j, k + 1);
        a[i - 1][j] = 1;
    }
    
}
int main() {
    int t; cin >> t;
    while(t--) {
        init();
        v.clear();
        if(a[1][1] && a[n][n]) {
            a[1][1] = 0;
            b_t(1, 1, 1);
        }
        if(ok) {
            cout << cnt << " ";
            for(int i = 0; i < v.size(); i++) {
                for(int j = 0; j < v[i].size(); j++) {
                    cout << v[i][j];
                }
                cout << " ";
            }
            cout << endl;
        }
        else cout << "-1\n";
    }
}