#include<bits/stdc++.h>
using namespace std;

vector<string> res;
void init() {
	queue<string> q;
	q.push("6");
	q.push("8");
	res.push_back("6");
	res.push_back("8");
	while(1) {
		string t1 = q.front(); q.pop();
		if(t1.length() == 15) break;
		res.push_back(t1 + "6");
		res.push_back(t1 + "8");
		q.push(t1 + "6");
		q.push(t1 + "8");
	}
}
int main() {
	init();
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<string> tmp;
		for(string x : res) {
			if(x.length() == n + 1) break;
			tmp.push_back(x);
		}
		cout << tmp.size() << endl;
		for(string x : tmp) {
			cout << x << " ";
		}
		cout << endl;
	}
}
