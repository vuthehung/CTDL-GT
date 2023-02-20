#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int a[n];
        for(int &x : a) cin >> x;
        int l = 0, r;
        vector<int> v;
        while(l <= (n - k)) {
            int max = 0;
            for(int i = l; i < l + k; i++) {
                if(max < a[i]) max = a[i];
            }
            v.push_back(max);
            l++;
        }
        for(int it : v) cout << it << " ";
        cout << endl;
    }
}