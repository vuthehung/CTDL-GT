#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 1;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        vector<vector<int>> v;
        for(int i = 0; i < n - 1; i++) {
            vector<int> x;
            int min = i;
            for(int j = i + 1; j < n; j++) {
                if(a[j] < a[min]) {
                    min = j;
                }
            }
            if(min != i) swap(a[i], a[min]);
            for(int k = 0; k < n; k++) x.push_back(a[k]);
            v.push_back(x);
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