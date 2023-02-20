#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];   
        for(int &x : a) cin >> x;
        int r = a[max_element(a, a + n) - a], l = a[min_element(a, a + n) - a];
        set<int> st;
        for(int x : a) st.insert(x);
        int cnt = 0;
        for(int i = l; i <= r; i++) {
            if(st.find(i) == st.end()) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}