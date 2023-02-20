#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
void solve(int a[], int n, int k) {
    sort(a, a + n, cmp);
    for(int i = 0; i < k; i++) cout << a[i] << " ";
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int a[n];
        for(int &x : a) cin >> x;
        solve(a, n, k);
        cout << endl;
    }
}