// cho 2 mang A, B. Ting gia tri min cua bieuthuc P = A[0]* B[0] + ... + A[n - 1]* B[n - 1]
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n], b[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n, greater<int>());
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += a[i] * b[i]; 
        }
        cout << ans << endl;
    }
}