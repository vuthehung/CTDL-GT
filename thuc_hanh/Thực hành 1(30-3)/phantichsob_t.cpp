#include<bits/stdc++.h>
using namespace std;
int n, a[11], cnt = 0;
vector<vector<int>> v;
void in(int m) {
    vector<int> x;
    for(int i = 1; i <= m; i++) {
        x.push_back(a[i]);
    }
    v.push_back(x);
}
void b_t(int i, int j, int s) {
    int k;
    for(int k = j; k >= 1; k--) {
        if(s + k <= n) {
            a[i] = k;
            s += k;
            if(s == n) {
                cnt++;
                in(i);
            }else b_t(i + 1, k, s);
            s -= k;
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        v.clear();
        cnt = 0;
        cin >> n; 
        b_t(1, n, 0);
        cout << cnt << endl;
        for(int i = 0; i < v.size(); i++) {
            cout << "(";
            for(int j = 0; j < v[i].size(); j++) {
                cout << v[i][j];
                if(j == v[i].size() - 1) cout << ")";
                else cout << " ";
            }
            cout << " ";
        }
        cout << endl;
    }
}