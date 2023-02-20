#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second) return a.second > b.second;
    else {
        return a.first < b.first;
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
        vector<pair<int, int>> v;
        for(auto it : mp) v.push_back(it);
        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < v.size(); i++) {
            for(int j = 1; j <= v[i].second; j++) {
                cout << v[i].first << " ";
            }
        } 
        cout << endl;
    }
} 