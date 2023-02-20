//chuyen xau nhi phan sang ma gray

#include<bits/stdc++.h>
using namespace std;
void btog(string s) {
    string gray = "";
    gray += s[0];
    for(int i = 1; i < s.length(); i++) {
        if(s[i - 1] == '1') {
            if(s[i] == '1') gray += '0';
            else gray += '1';
        }else gray += s[i];
    }
    cout << gray << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        btog(s);
    }
}