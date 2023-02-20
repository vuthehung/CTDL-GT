// chuyen tu Gray sang nhi phan
#include<bits/stdc++.h>
using namespace std;
void graytoBinary(string s) {
    string res = "";
    res += s[0];
    for(int i = 1; i < s.length(); i++) {
        if(s[i] == '0') {
            res += res[i - 1];
        }else {
            if(res[i - 1] == '1') res += '0';
            else res += '1';
        }
    }
    cout << res << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        graytoBinary(s);
    }
}