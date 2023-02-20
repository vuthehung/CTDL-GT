#include<bits/stdc++.h>
using namespace std;

vector<string> res;
void init() {
	queue<string> q;
	q.push("9");
	while(res.size() < 520) {
		string top = q.front(); q.pop();
		res.push_back(top);
		q.push(top + "0");
		q.push(top + "9");
	}
}
int main() {
	init();
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		for(int i = 0; i < res.size(); i++) {
			if(stoll(res[i]) % n == 0) {
				cout << res[i] << endl;
				break;
			}
		}
	}
}
