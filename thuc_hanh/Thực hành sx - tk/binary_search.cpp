#include<bits/stdc++.h>
using namespace std;
int binary_search1(int a[], int n, int x) {
    int res = -1;
    int l = 0, r = n - 1;
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
int main() {
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        int a[n];
        for(int &i : a) cin >> i;
        int idx = binary_search1(a, n, x);
        if(idx != -1) {
            cout << idx + 1;
        }else cout << "NO";
        cout << endl;
    }
}