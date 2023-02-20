#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    sort(a, a + n);
    int min = 100000000;
    int l = 0;
    while(l < n - 1) {
        if(min > (a[l + 1] - a[l])) {
            min = a[l + 1] - a[l];
        }
        l++;
    }
    cout << min << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}