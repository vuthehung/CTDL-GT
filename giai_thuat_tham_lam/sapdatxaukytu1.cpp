#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;     
        map<char, int> mp;
        for(char c : s) mp[c]++;
        int max_fre = 0;
        for(auto it : mp) {
            max_fre = max(max_fre, it.second);
        }
        if(s.length() - max_fre >= max_fre - 1) {
            cout << "1\n";
        }else cout << "-1\n";
    }
}