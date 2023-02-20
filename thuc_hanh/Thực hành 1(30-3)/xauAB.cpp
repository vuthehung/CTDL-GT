#include<bits/stdc++.h>
using namespace std;
int n, a[11], ok;
void ktao() {
    cin >> n;
    for(int i = 1; i <= n; i++) a[i] = 0;
    ok = 1;
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

int main() {
    int t; cin >> t;
    while(t--) {
        vector<vector<char>> v;
        ktao();
        while(ok) {
            vector<char> x;
            for(int i = 1; i <= n; i++) {
                if(a[i] == 0) {
                    x.push_back('A');
                }else x.push_back('B');
            } 
            v.push_back(x);
            sinh();
        }
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[i].size(); j++) {
                cout << v[i][j];
            }
            if(i < v.size() - 1) cout << ",";
        }
        cout << endl;
    }
}