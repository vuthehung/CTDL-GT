#include<bits/stdc++.h>
using namespace std;
int n, ok, a[11], b[11];
void ktao() {
    ok = 1;
    cin >> n;
    for(int i = 1; i <= n; i++) a[i] = i;
    for(int i = 0; i < n; i++) cin >> b[i];
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
int check(vector<int> x) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(x[i] == b[i]) cnt++;
    }
    if(cnt == n) return 1;
    return 0;
}
int main() {
    int t; cin >> t;
    while(t--) {
        ktao();
        vector<vector<int>> v;
        while(ok) {
            vector<int> x;
            for(int i = 1; i <= n; i++) {
                x.push_back(a[i]);
            }
            sinh();
            v.push_back(x);
        }
        for(int i = 0; i < v.size(); i++) {
            if(check(v[i]) == 1) {
                cout << i + 1;
            }
        }
        cout << endl;
    }
}