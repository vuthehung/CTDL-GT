#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        int a[n], b[m];
        set<int> st1;
        set<int> st2;
        for(int &x : a) {
            cin >> x;
            st1.insert(x);
            st2.insert(x);
        }
        for(int &x : b){
            cin >> x;
            st1.insert(x);
        }
        vector<int> v;
        for(int i = 0; i < m; i++) {
            if(st2.find(b[i]) != st2.end()) {
                v.push_back(b[i]);
            }
        }
        for(int it : st1) cout << it << " ";
        cout << endl;
        for(int it : v) cout << it << " ";
        cout << endl;
    }
}