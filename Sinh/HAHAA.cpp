#include<bits/stdc++.h>
using namespace std;
int n, a[17], ok;
void ktao() {
    cin >> n;
    for(int i = 1; i <= n; i++) a[i] = 0;
}
void sinh() {
    int i = n;
    while(i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if(i == 0) ok = 0;
    else a[i] = 1;
}
bool check1() {
    if(a[1] == 0 && a[n] == 1) return true;
    return false;
}
bool check2() {
    for(int i = 1; i < n; i++) {
        if(a[i] == 0 && a[i + 1] == 0) return false;
    }
    return true;
}
int main() {
    int t; cin >> t;
    while(t--) {
        vector<vector<char>> v;
        ktao();
        ok = 1;
        while(ok) {
            vector<char> x;
            if(check1() && check2()) {
                for(int i = 1; i <= n; i++){
                    if(a[i] == 0) {
                        x.push_back('H');
                    }else if(a[i] == 1) x.push_back('A');
                }
                v.push_back(x);
            }
            sinh();
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[i].size(); j++) {
                cout << v[i][j];
            }
            cout << endl;
        }
    }
}