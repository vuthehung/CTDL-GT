#include<bits/stdc++.h>
using namespace std;
int check(string s) {
	stack<char> a;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '[' || s[i] == '{' || s[i] == '(') {
			a.push(s[i]);
		}else if(s[i] == ']') {
			if(a.top() == '[') {
				a.pop();
			}
		}else if(s[i] == '}') {
			if(a.top() == '{') {
				a.pop();
			}
		}else if(s[i] == ')') {
			if(a.top() == '(') {
				a.pop();
			}
		}
	}
	if(a.empty()) return 1;
	return 0;
}
int main() {
	int t; cin >> t;
	cin.ignore();
	while(t--) {
		string s;
		cin >> s;
		if(check(s)) {
			cout << "YES\n";
		}else {
			cout << "NO\n";
		}
	}
}
