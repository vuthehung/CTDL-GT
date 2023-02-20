#include<bits/stdc++.h>
using namespace std;


void solve(int n) {
	queue<string> q;
	q.push("6");
	q.push("8");
	int i = 0;
	while(1) {
		string top = q.front(); q.pop();
		q.push(top + "6");
		q.push(top + "8");
		string tmp = top;
		reverse(tmp.begin(), tmp.end());
		cout << top + tmp << " ";
		i++;
		if(i == n) break;
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		solve(n);
		cout << endl;
	}
}
