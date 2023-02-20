#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        int a[n], b[m];
        set<int> st;
        set<int> st2;
        for(int &x : a) {
            cin >> x;
            st.insert(x);
            st2.insert(x);
        }
        for(int &x : b) {
            cin >> x;
            st.insert(x);
        }
        for(int it : st) cout << it << " ";
        cout << endl;
        for(int i = 0; i < m; i++) {
            if(st2.find(b[i]) != st2.end()) {
                cout << b[i] << " ";
            }
        }
        cout << endl;
    }
}