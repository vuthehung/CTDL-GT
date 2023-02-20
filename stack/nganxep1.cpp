#include<bits/stdc++.h>
using namespace std;

void in(stack<string> st) {
	vector<string> tmp;
	while(!st.empty()) {
		tmp.push_back(st.top());
		st.pop();
	}
	for(int i = tmp.size() - 1; i >= 0; i--) cout << tmp[i] << " ";
}
int main() {
	string s;
	stack<string> st;
	while(getline(cin, s)) {
		stringstream ss(s);
		string x;
		while(ss >> x) {
			if(x == "show") {
				if(st.empty()) cout << "empty";
				else in(st);
				cout << endl;
			}
			else if(x == "pop") st.pop();
			else if(x != "push") st.push(x);
		}
	}	  
}
