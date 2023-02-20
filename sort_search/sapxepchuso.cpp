#include<bits/stdc++.h>
using namespace std;
void solve(int a[], int n) {
    set<int> st;
    for(int i = 0; i < n; i++) {
        string s = to_string(a[i]);
        for(int j = 0; j < s.length(); j++) {
            st.insert(s[j] - '0');
        }
    }
    for(int x : st) cout << x << " ";
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        solve(a, n);
        cout << endl;
    }
}