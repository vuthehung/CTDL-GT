#include<bits/stdc++.h>
using namespace std;
int n, a[13], cnt, ok;
vector<vector<int>> v;
void init() {
    cin >> n;
    cnt = 0;
    ok = 1;
    for(int i = 1; i <= n; i++) a[i] = 6;
}
void in() {
    vector<int> x;
    for(int i = 1; i <= n; i++) {
        x.push_back(a[i]);
    }
    v.push_back(x);
}
void sinh() {
    int i = n;
    while(i >= 1 && a[i] == 8) {
        a[i] = 6;
        i--;
    }
    if(i == 0) ok = 0;
    else a[i] = 8;
}
int main() {
    int t; cin >> t;
    while(t--) {
        init();
        v.clear();
        while(ok) {
            cnt++;
            in();
            sinh();
        }
        cout << cnt << endl;
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[i].size(); j++) {
                cout << v[i][j];
            }
            cout << " ";
        }
        cout << endl;
    }
}