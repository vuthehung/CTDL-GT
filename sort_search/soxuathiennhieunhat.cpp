#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if(a.second.first != b.second.first) {
        return a.second.first > b.second.first;
    }
    return a.second.second < b.second.second;
}
void TC() {
    int n; cin >> n;
    int a[n];
    map<int, pair<int, int>> mp;
    vector<pair<int, pair<int, int>>> v;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(mp.find(a[i]) == mp.end()) { // a[i] chua co trong map
            mp[a[i]] = {1, i};
        }else {
            mp[a[i]].first++;
        }
    }
    for(auto it : mp) {
        v.push_back(it);
    }
    sort(v.begin(), v.end(), cmp);
    int ok = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].second.first > (n / 2)) {
            cout << v[i].first;
            ok = 1;
            break;
        }
    }
    if(ok == 0) cout << "NO";
}
int main() {
    int t; cin >> t;
    while(t--) {
        TC();
        cout << endl;
    }
}