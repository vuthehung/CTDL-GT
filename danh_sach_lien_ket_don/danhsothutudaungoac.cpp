#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	cin.ignore();
	while(t--) {
		stack<pair<char, int> > st;
		string s; 
		getline(cin, s);
		vector<char> a;
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '(' || s[i] == ')') {
				a.push_back(s[i]);
			}
		}
		int res[a.size()];
		int cnt = 0;
		for(int i = 0; i < a.size(); i++) {
			if(a[i] == '(') {
				++cnt;
				st.push({s[i], cnt});
				res[i] = cnt;
			}else if(a[i] == ')') {
				res[i] = st.top().second;
				st.pop();
			}
		}
		for(int i = 0; i < a.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
}
