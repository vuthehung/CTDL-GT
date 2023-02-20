#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		stack<pair<char, int> > st;	
		string s; cin >> s;
		int ans = 0, n = s.length();
		vector<int> pos(n, 0);
		for(int i = 0; i < n; i++) {
			if(s[i] == ')' && !st.empty() && st.top().first == '(') {
				pos[i] = pos[i - 1];
				if(st.top().second != 0) {
					pos[i] += pos[st.top().second - 1];
				}
				pos[i] += 2;
				st.pop();
			}else {
				st.push({s[i], i});
			}
		}
		for(int i = 0; i < n; i++) {
			ans = max(ans, pos[i]);
		}
		cout << ans << endl;
	}
}
