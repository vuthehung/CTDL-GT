#include<bits/stdc++.h>
using namespace std;

int main() {
	queue<string> q;	
	int t; cin >> t;
	cin.ignore();
	while(t--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string x;
		while(ss >> x) {
			if(x == "PRINTFRONT") {
				if(q.empty()) {
					cout << "NONE\n";
				}else {
					cout << q.front() << endl;
				}
			}else if(x == "POP") {
				if(q.empty()) continue;
				else q.pop();
			}else if(x != "PUSH") {
				q.push(x);
			}
		} 
	}
	return 0;
}
