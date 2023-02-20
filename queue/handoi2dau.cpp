#include<bits/stdc++.h>
using namespace std;

int main() {
	deque<int> q;
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		if(s == "PUSHFRONT") {
			int x; cin >> x;
			q.push_front(x);
		}else if(s == "PUSHBACK") {
			int x; cin >> x;
			q.push_back(x);
		}else if(s == "POPFRONT") {
			if(q.empty()) continue;
			else q.pop_front();
		}else if(s == "POPBACK") {
			if(q.empty()) continue;
			else q.pop_back();
		}else if(s == "PRINTFRONT") {
			if(q.empty()) {
				cout << "NONE\n";
			}else cout << q.front() << endl;
		}else if(s == "PRINTBACK") {
			if(q.empty()) cout << "NONE\n";
			else cout << q.back() << endl;
		}
	}
}
