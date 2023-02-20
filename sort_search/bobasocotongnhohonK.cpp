#include<bits/stdc++.h>
using namespace std;
// vi tri cuoi cung nho hon x.
int last_pos(int a[], int l, int r, int x) {
    int res = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] < x) {
            res = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    return res;
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int a[n];
        for(int &x : a) cin >> x;
        sort(a, a + n);
        long long ans = 0;
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                int res = last_pos(a, j + 1, n - 1, (k - a[i] - a[j]));
                if(res != - 1) ans += res - j;
            }
        }
        cout << ans << endl;
    }
}