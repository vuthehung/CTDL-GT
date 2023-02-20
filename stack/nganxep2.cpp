#include<bits/stdc++.h>
using namespace std;
void in(stack<string> st) {
	if(!st.empty()) {
		cout << st.top();
	}
}
int main() {
	stack<string> st;
	int q; cin >> q;
	cin.ignore();
	while(q--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string tmp;
		while(ss >> tmp) {
			if(tmp == "PRINT") {
				if(st.empty()) cout << "NONE";
				else in(st);
				cout << endl;
			}else if(tmp == "POP") {
				if(st.empty()) {
					continue;
				}else {
					st.pop();
				}
			}else if(tmp != "PUSH") st.push(tmp);
		}
	}
}
