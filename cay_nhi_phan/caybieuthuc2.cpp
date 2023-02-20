#include<bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(string s) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while(ss >> x) v.push_back(x);
	
	queue<ll> q;
	for(int i = v.size() - 1; i >= 0; i--) {
		if(v[i] != "+" && v[i] != "-" && v[i] != "*" && v[i] != "/") {
			q.push(stoll(v[i]));
		}else {
			ll t1 = q.front(); q.pop();
			ll t2 = q.front(); q.pop();
			//int res;
			if(v[i] == "+") {
				ll res = t2 + t1;
				q.push(res);
			}else if(v[i] == "-") {
				ll res = t2 - t1;
				q.push(res);
			}else if(v[i] == "*") {
				ll res = t2 * t1;
				q.push(res);
			}else if(v[i] == "/") {
				ll res = t2 / t1;
				q.push(res);
			}
		}
	}
	cout << q.front() << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		cin.ignore();
		string s;
		getline(cin, s);
		solve(s);
	}
}
