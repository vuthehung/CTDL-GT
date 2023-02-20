#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        set<int> st;
        for(int x : a) st.insert(x);
        vector<int> v;
        for(int x : st) v.push_back(x);
        if(v.size() == 1) cout << "-1";
        else cout << v[0] << " " << v[1];
        cout << endl;
    }
}