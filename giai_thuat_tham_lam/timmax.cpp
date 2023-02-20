// cho mang A. tim max cua a[i]* i (i = 0, 1,.., n - 1). bang cach doi cho cac ptu.

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += a[i] * i % mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
}