#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int a[n];
        for(int &x : a) cin >> x;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
        if(mp.find(k) == mp.end()) {
            cout << "-1";
        }else {
            cout << mp[k];
        }
        cout << endl;
    }
}