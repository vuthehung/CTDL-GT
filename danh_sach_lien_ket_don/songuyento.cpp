#include<bits/stdc++.h>
using namespace std;
vector<string> res;
void init() {
	queue<string> q;
	q.push("2");
	q.push("3");
	q.push("5");
	q.push("7");
	while(1) {
		string top = q.front();
		q.pop();
		if(top.length() == 10) break;
		res.push_back(top);
		q.push(top + "2");
		q.push(top + "3");
		q.push(top + "5");
		q.push(top + "7");
	}
}

bool check1(string s) {
	if(s[s.length() - 1] != '2') return false;
	return true;
}
bool check2(string s) {
	for(int i = 0; i < s.length(); i++) {
		if(s[i] != '2' || s[i] != '3' || s[i] != '5' || s[i] != '7') {
			return false;
		}	
	}
	return true;
}
int main() {
	init();
	vector<string> a;
	int n; cin >> n;
	for(int i = 0; i < res.size(); i++) {
		if(res[i].length() == n && check1(res[i]) && check2(res[i])) {
			
		}
	}
}
