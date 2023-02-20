#include<bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	stack<char> st;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == ']') {
			string tmp = "";
			while(!st.empty() && st.top() != '[') {
				tmp = st.top() + tmp;
				st.pop();
			}
			st.pop();
			string num;
			while(!st.empty() && isdigit(st.top())) {
				num = st.top() + num;
				st.pop();
			}
			int number = 1;
			if(num.length()) number = stoi(num);
			string ans;
			while(number--) {
				ans += tmp;
			}
			for(int i = 0; i < ans.length(); i++) {
				st.push(ans[i]);
			}
		}else st.push(s[i]);
	}
	string res = "";
	while(!st.empty()) {
		res = st.top() + res;
		st.pop();
	}
	cout << res << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
//#include<bits/stdc++.h>
//using namespace std;
//
//void Solve() {
//	string s; cin >> s;
//	stack<char> st;
//	for(int i=0; i<s.size(); i++) {
//		if(s[i] == ']') {
//			string tmp = "";
//			while(!st.empty() && st.top()!='[') {
//				tmp = st.top() + tmp;
//				st.pop();
//			}
//			st.pop();
//			string num;
//			while(!st.empty() && isdigit(st.top())) {
//				num = st.top() + num;
//				st.pop();
//			}
//			int number = 1;
//			if(num.size()) number = stoi(num);
//			string ans;
//			while(number--) ans += tmp;
//			for(int i=0; i<ans.size(); i++) st.push(ans[i]); 
//		}
//		else st.push(s[i]);
//	}
//	string res = "";
//	while(!st.empty()) {
//		res = st.top() + res;
//		st.pop();
//	}
//	cout << res << endl;
//}
//
//main() {
//	int t; cin >> t;
//	while(t--) {
//		Solve();
//	}
//}
