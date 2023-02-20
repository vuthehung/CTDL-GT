#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        int a[n], b[m];
        multiset<int> st;
        for(int &x : a) {
            cin >> x;
            st.insert(x);
        }
        for(int &x : b) {
            cin >> x;
            st.insert(x);
        }
        for(int it : st) cout << it << " ";
        cout << endl;
        
    }
}