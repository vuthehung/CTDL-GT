#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.second.second < b.second.second;
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        map<int, pair<int, int>> mp;
        for(int i = 0; i < n; i++) {
            if(mp.find(a[i]) == mp.end()) {
                mp[a[i]] = {1, i};
            }else {
                mp[a[i]].first++;
            }
        }
        vector<pair<int, pair<int, int>>> v;
        for(auto it : mp) v.push_back(it);
        sort(v.begin(), v.end(), cmp);
        int ok = 1;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].second.first > 1) {
                cout << v[i].first;
                ok = 1;
                break;
            }else {
               ok = 0;
            }
        }
        if(ok == 0) cout << "NO";
        cout << endl;
    }
}