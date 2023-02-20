#include<bits/stdc++.h>
using namespace std;
int solve() {
    int n, s, m;
    cin >> n >> s >> m;
    int sum = s * m; // so luong thuc can cho s ngay
    int ngay = s - s/7; // so ngay co the mua luong thuc
    if(sum > ngay * n) return -1;
    for(int i = 1; i <= ngay; i++) {
        if(i * n >= sum) {
            return i;
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        int res = solve();
        cout << res << endl;
    }
}