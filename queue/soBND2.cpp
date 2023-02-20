#include<bits/stdc++.h>
using namespace std;


int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		queue<string> q;
		q.push("1");
		while(1) {
			string t = q.front(); q.pop();
			if(stoll(t) % n == 0) {
				cout << t << endl;
				break;
			}
			q.push(t + "0");
			q.push(t + "1");
		}
	}
}
