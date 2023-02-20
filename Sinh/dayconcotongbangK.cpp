#include<bits/stdc++.h>
using namespace std;
int n, k, a[1001], b[1001], ok;
void ktao() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = 0;
    }
}
void sinh() {
    int i = n; 
    while(i >= 1 && b[i] == 1) {
        b[i] = 0;
        i--;
    }
    if(i == 0) ok = 0;
    else b[i] = 1;
}
int main() {
    ktao();
    ok = 1;
    int cnt = 0;
    vector<vector<int>> v;
    while(ok) {
        int s = 0;
        for(int i = 1; i <= n; i++) {
            s += a[i] * b[i];
        }
        vector<int> x;
        if(s == k) {
            for(int i = 1; i <= n; i++) {
                if(b[i] == 1) {
                    x.push_back(a[i]);
                }
            }
            cnt++;
        }
        v.push_back(x);
        sinh();
    }
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << cnt;
}