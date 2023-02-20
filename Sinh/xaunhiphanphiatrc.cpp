#include<bits/stdc++.h>
using namespace std;

void truoc(string s) {
    int i = s.length() - 1;
    while(i >= 0 && s[i] == '0') {
        s[i] = '1';
        i--;
    }
    if(i != - 1) s[i] = '0';
    cout << s << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        truoc(s);
    }
}