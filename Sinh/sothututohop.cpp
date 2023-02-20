#include<bits/stdc++.h>
using namespace std;
int n, k, ok, a[16], b[16];
void ktao() {
    ok = 1;
    cin >> n >> k;
    for(int i = 1; i <= k; i++) a[i] = i;
    for(int i = 0; i < k; i++) cin >> b[i];
}
void sinh() {
    int i = k;
    while(i >= 1 && a[i] == n - k + i) i--;
    if(i == 0) ok = 0;
    else {
        a[i]++;
        for(int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
    }
}
bool check(vector<int> x) {
    int cnt = 0;
    for(int i = 0; i < k; i++) {
        if(x[i] == b[i]) cnt++;
    }
    if(cnt == k) return true;
    return false;
}
int main() {
    int t; cin >> t;
    while(t--) {
        ktao();
        vector<vector<int>> v;
        while(ok) {
            vector<int> x;
            for(int i = 1; i <= k; i++) {
                x.push_back(a[i]);
            }
            sinh();
            v.push_back(x);
        }
        for(int i = 0; i < v.size(); i++) {
            if(check(v[i])) {
                cout << i + 1;
            }
        }
        cout << endl;
    }
}