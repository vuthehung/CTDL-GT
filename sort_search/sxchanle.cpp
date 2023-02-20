#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    vector<int> chan, le;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 0) {
            chan.push_back(a[i]);
        }else {
            le.push_back(a[i]);
        }
    }
    sort(chan.begin(), chan.end());
    sort(le.begin(), le.end(), greater<int>());
    int i = 0, j = 0;
    for(int k = 0; k < n; k++) {
        if(a[k] % 2 == 1) {
            cout << le[j++] << " ";
        }else cout << chan[i++] << " ";
    }
    return 0;
}