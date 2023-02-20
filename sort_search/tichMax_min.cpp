#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        long long a[n], b[m];
        for(long long &x : a) cin >> x;
        for(long long &y : b) cin >> y;
        sort(a, a + n, greater<int>());
        sort(b, b + m);
        long long t = a[0] * b[0];
        cout << t << endl;
    }
}