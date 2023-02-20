#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b) {
	return a.second > b.second;
}
void check() {
    int d;
    string s;
    cin >> d >> s;
    map<char, int> mp;
    for(char x : s) mp[x]++;
    vector<pair<char, int> > v;
    for(auto it : mp) v.push_back(make_pair(it.first, it.second));
    sort(v.begin(), v.end(), cmp);
    int len = s.length();
    char kq[100] = {};
    for(int i = 0; i < v.size(); i++) {
        int tansuat = v[i].second;
        for(int k = 0; k < tansuat; k++) {
            if(i + k * d > len) return;
            kq[i + (k * d)] = v[i].first;
        }
    }
    for(int i = 0; i < s.length(); i++) cout << kq[i];
}
int main() {
    int t; cin >> t;
    while(t--) {
        check();
    }
}
