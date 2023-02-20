#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> v;
void init() {
    vector<string> a;
    a.push_back("0"); a.push_back("1");
    v.push_back(a);
    for(int i = 2; i <= 10; i++) {
        vector<string> b(v[i - 2]);
        reverse(b.begin(), b.end());
        vector<string> x;
        for(int j = 0; j < v[i - 2].size(); j++) {
            x.push_back("0" + v[i - 2][j]);
        }
        for(int j = 0; j < b.size(); j++) {
            x.push_back("1" + b[j]);
        }
        v.push_back(x);
    }
}
int main() {
    init();
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(string x : v[n - 1]) {
            cout << x << " ";
        }
        cout << endl;
    }
}