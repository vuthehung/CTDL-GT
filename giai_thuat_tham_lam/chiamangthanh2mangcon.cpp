#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int a[n];
        int x = min(k, n - k); // so sanh de mang co it phan tu nhat luu cac so nho nhat
        int b[x], c[n - x]; 
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int l = 0, j = 0;
        for(int i = 0; i < n; i++) {
            if(i < x) {
                b[l++] = a[i];
            }else if(i >= x) {
                c[j++] = a[i];
            }
        }
        int sum1 = accumulate(b, b + x, 0);
        int sum2 = accumulate(c, c + n - x, 0);
        cout << abs(sum1 - sum2) << endl;
    }
}