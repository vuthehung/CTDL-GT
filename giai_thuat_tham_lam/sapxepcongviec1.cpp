#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        // int s[n], f[n];
        // for(int i = 0; i < n; i++) cin >> s[i] >> f[i];
        // // for(int i = 0; i < n; i++) cin >> f[i];
        pair<int, int> a[n];
        for(int i = 0; i < n; i++) {
            // a[i].first = s[i];
            // a[i].second = f[i];
            cin >> a[i].first >> a[i].second;
        } 
        sort(a, a + n, cmp);
        int cnt = 1, j = 0;
        for(int i = 1; i < n; i++) {
            if(a[i].first >= a[j].second) {
                cnt++;
                j = i;
            }
        }
        cout << cnt << endl;
    }
}