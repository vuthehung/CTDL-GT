#include<bits/stdc++.h>
using namespace std;
int n, k, a[100001];
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - k + 1; i++) {
        int res = *max_element(a + i, a + i + k);
        cout << res << " ";
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
}