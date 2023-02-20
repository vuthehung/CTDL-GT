#include<bits/stdc++.h>
using namespace std;

string form = "012345";
bool check(string s) {
	for(auto it : form) {
		if(count(s.begin(), s.end(), it) > 1) return false;
	}
	return true;
}
void solve() {
	int l, r;
	cin >> l >> r;
	queue<string> q;
	int cnt = 0;
	vector<string> v;
	q.push("1");
	q.push("2");
	q.push("3");
	q.push("4");
	q.push("5");
	while(!q.empty()) {
		string top = q.front(); q.pop();
		if(stoi(top) > r) break;
		else if(stoi(top) >= l && check(top)){
			cnt++;
		}
		q.push(top + "0");
		q.push(top + "1");
		q.push(top + "2");
		q.push(top + "3");
		q.push(top + "4");
		q.push(top + "5");
	}
	cout << cnt << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
