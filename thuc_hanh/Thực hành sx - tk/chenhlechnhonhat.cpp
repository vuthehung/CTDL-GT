#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        sort(a, a + n);
        int min = INT_MAX;
        int l = 0;
        while(l < n - 1) {
            if(min > (a[l + 1] - a[l])) {
                min = a[l + 1] - a[l];
            }
            l++;
        }
        cout << min << endl;
    }
}