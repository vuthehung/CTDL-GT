#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	cin.ignore();
	while(t--) {
		stack<string> st;
		string s;
		getline(cin, s);
		stringstream ss(s);
		string x;
		while(ss >> x) {
			st.push(x);
		}
		while(!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
}
