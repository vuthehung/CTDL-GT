#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        vector<vector<int>> v;
        for(int i = 0; i < n - 1; i++) {
            vector<int> x;
            for(int j = i + 1; j < n; j++) {
                if(a[i] > a[j]){
                    swap(a[i], a[j]);
                }
            }
            for(int k = 0; k < n; k++) x.push_back(a[k]);
            v.push_back(x);
        }
        for(int i = v.size() - 1; i >= 0; i--){
            cout << "Buoc " << i + 1 << ": ";
            for(int j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}