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
            bool ok = false;
            for(int j = 0; j < n - i - 1; j++) {
                if(a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    ok = true;
                }
            }
            if(ok) {
                for(int i = 0; i < n; i++) x.push_back(a[i]);
                v.push_back(x);
            }else break;
        }
        for(int i = v.size() - 1; i >= 0; i--) {
            cout << "Buoc " << i + 1 << ": ";
            for(int j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}