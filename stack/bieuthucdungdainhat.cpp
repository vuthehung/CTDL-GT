#include <bits/stdc++.h>
using namespace std;

//main()
//{
//    int t; cin >> t;
//    while(t--) {
//		string s; cin >> s;
//		stack <int> st;
//		st.push(-1);
//			int ans = 0;
//			for(int i=0; i<s.size(); i++) {
//				if(s[i] == '(') st.push(i);
//				else {
//					st.pop();
//					if(!st.empty()) ans += 2;
//					else if(st.empty()) st.push(i);
//				}
//			}
//			cout << ans << endl;
//	}
//}
int main() {
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		stack<char> st;
		st.push(-1);
		int ans = 0;
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '(') st.push(s[i]);
			else if(s[i] == ')' && st.top() == '(') {
				st.pop();
				ans += 2;
			}
		}
		cout << ans << endl;
	}
}




