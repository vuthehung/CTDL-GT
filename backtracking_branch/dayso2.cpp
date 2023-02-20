#include<bits/stdc++.h>
using namespace std;
int n, a[11];
void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void back_track(int index) {
    vector<vector<int>> v;
    if(index == 0) return;
    vector<int> x;
    for(int i = 1; i <= index; i++) {
        x.push_back(a[i]);
    }
    v.push_back(x);
    x.clear();
    for(int i = 1; i < index; i++) {
        a[i] += a[i + 1];
    }
    back_track(index - 1);
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        cout << "[";
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if(j == v[i].size() - 1) cout << "] ";
            else cout << " ";
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        init();
        back_track(n);
        cout << endl;
    }
}