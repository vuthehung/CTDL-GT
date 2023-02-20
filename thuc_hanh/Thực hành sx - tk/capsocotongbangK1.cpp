#include<bits/stdc++.h>
using namespace std;
int first_pos(int a[], int l, int r, int x) {
    int res = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] == x) {
            res = mid;
            r = mid - 1;
        }else if(a[mid] < x) l = mid + 1;
        else r = mid -1;
    }
    return res;
}
int last_pos(int a[], int l, int r, int x) {
    int res = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] == x) {
            res = mid;
            l = mid + 1;
        }else if(a[mid] < x) l = mid + 1;
        else r = mid -1;
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
        for(int i = 0; i < n - 1; i++) {
            int l = first_pos(a, i + 1, n - 1, k - a[i]);
            int r = last_pos(a, i + 1, n - 1, k - a[i]);
            if(l != - 1) ans += r - l + 1;
        }
        cout << ans << endl;
    }
}