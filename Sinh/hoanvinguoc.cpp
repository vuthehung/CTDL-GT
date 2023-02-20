#include<bits/stdc++.h>
using namespace std;
int n, a[11], ok;
void ktao() {
    cin >> n;
    for(int i = 1; i <= n; i++) a[i] = i;
}
void sinh() {
    int i = n - 1;
    while(i >= 1 && a[i] > a[i + 1]) i--;
    if(i == 0) ok = 0;
    else {
        int j = n;
        while(a[i] > a[j]) j--;
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        vector<vector<int>> v;
        ktao();
        ok = 1;
        while(ok) {
            vector<int> x;
            for(int i = 1; i <= n; i++) x.push_back(a[i]);
            v.push_back(x);
            sinh();
        }
        for(int i = v.size() - 1; i >= 0; i--) {
            for(int j = 0; j < v[i].size(); j++) {
                cout << v[i][j];
            }
            cout << " ";
        }
        cout << endl;
    }
}