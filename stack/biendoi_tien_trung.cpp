#include<bits/stdc++.h>
using namespace std;
void solve(string s) {
	stack<string> st;
	for(int i = s.length() - 1; i >= 0; i--){
		if(isalpha(s[i])) {
			st.push(string(1, s[i]));
		}else {
			string opr1 = st.top(); st.pop();
			string opr2 = st.top(); st.pop();
			string res = "(" + opr1 + s[i] + opr2 + ")";
			st.push(res);
		}
	}
	cout << st.top() << endl;
}
int main() {
	int t; cin >> t;
	cin.ignore();
	while(t--) {
		string s; cin >> s;
		solve(s);
	}
}
