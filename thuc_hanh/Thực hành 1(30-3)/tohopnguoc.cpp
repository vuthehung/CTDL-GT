#include<bits/stdc++.h>
using namespace std;
int n, k, a[20];
vector<vector<int>> v;
void b_t(int i) {
    for(int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
        if(i == k) {
            vector<int> x;
            for(int l = 1; l <= k; l++) {
                x.push_back(a[l]);
            }
            v.push_back(x);
        }else b_t(i + 1);
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        v.clear();
        cin >> n >> k;
        b_t(1);
        reverse(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}