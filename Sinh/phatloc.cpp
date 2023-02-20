#include<bits/stdc++.h>
using namespace std;
int n, ok , a[16];
void ktao() {
    cin >> n;
    for(int i = 1; i <= n; i++) a[i] = 8;
}
void sinh() {
    int i = n;
    while(i >= 1 && a[i] == 6) {
        a[i] = 8;
        i--;
    }
    if(i == 0) ok = 0;
    else a[i] = 6;
}
bool check1() {
    if(a[1] == 8 && a[n] == 6) return true;
    return false;
}
bool check2() {
    for(int i = 1; i < n; i++) {
        if(a[i] == 8 && a[i + 1] == 8) return false;
    }
    return true;
}
bool check3() {
    for(int i = 1; i < n - 2; i++) {
        if(a[i] == 6 && a[i + 1] == 6 && a[i + 2] == 6 && a[i + 3] == 6)
            return false;
    }
    return true;
}
int main() {
    ktao();
    ok = 1;
    vector<vector<int>> v;
    while(ok) {
        vector<int> x;
        if(check1() && check2() && check3()) {
            for(int i = 1; i <= n; i++) {
                x.push_back(a[i]);
            }
        }
        v.push_back(x);
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