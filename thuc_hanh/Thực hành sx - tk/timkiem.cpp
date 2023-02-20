#include<bits/stdc++.h>
using namespace std;
bool binary_search(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] == x) return true;
        else if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        int a[n];
        for(int &x : a) cin >> x;
        if(binary_search(a, n, x)) {
            cout << "1";
        }else cout << "-1";
        cout << endl;
    }
}