#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 1;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        vector<vector<int>> v;
        for(int i = 0; i < n; i++) {
            vector<int> v1;
            int x = a[i], pos = i - 1;
            while(pos >= 0 && x < a[pos]) {
                a[pos + 1] = a[pos];
                pos--;
            }
            a[pos + 1] = x;
            for(int j = 0; j <= i; j++) v1.push_back(a[j]);
            v.push_back(v1);
        }
        for(int i = v.size() - 1; i >= 0; i--) {
            cout << "Buoc " << i << ": ";
            for(int j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}