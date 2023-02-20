#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        long long a[n], b[m], c[k];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        for(int i = 0; i < k; i++) cin >> c[i];
        vector<long long> v;
        int i = 0, j = 0, l = 0;
        while(i < n && j < m && l < k) {
            if(a[i] == b[j] && b[j] == c[l]) {
                v.push_back(a[i]);
                i++; j++; l++;
            }else if(a[i] <= b[j] && a[i] <= c[l]) {
                i++;
            }else if(b[j] <= a[i] && b[j] <= c[l]) {
                j++;
            }else l++;
        }
        if(v.size() == 0) cout << "-1";
        else {
            for(auto it : v) cout << it << " ";
        }
        cout << endl;
    }
}