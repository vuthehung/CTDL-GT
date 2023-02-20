#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, m;
int R1[1000005], L1[1000005], R2[1000005], L2[1000005], a[1000005], a1[1000005], a2[1000005];

void right1() {
	stack<int> st1;
	a1[n + 1] = 1e9;
	st1.push(n + 1);
	for(int i = n; i >= 1; i--) {
		while(!st1.empty() && a1[st1.top()] >= a1[i]) st1.pop();
		if(!st1.empty()) R1[i] = st1.top();
		else R1[i] = n + 1;
		st1.push(i);
	}
}
void right2() {
	stack<int> st2;
	a2[n + 1] = 1e9;
	st2.push(n + 1);
	for(int i = n; i >= 1; i--) {
		while(!st2.empty() && a2[st2.top()] >= a2[i]) st2.pop();
		if(!st2.empty()) R2[i] = st2.top();
		else R2[i] = n + 1;
		st2.push(i);
	}
}
void left1() {
	stack<int> st1;
	a1[0] = 1e9;
	st1.push(0);
	for(int i = 1; i <= n; i++) {
		while(!st1.empty() && a1[st1.top()] >= a1[i]) st1.pop();
		if(!st1.empty()) L1[i] = st1.top();
		else L1[i] = 0;
		st1.push(i);
	}
	
}
void left2() {
	stack<int> st2;
	a2[0] = 1e9;
	st2.push(0);
	for(int i = 1; i <= n; i++) {
		while(!st2.empty() && a2[st2.top()] >= a2[i]) st2.pop();
		if(!st2.empty()) L2[i] = st2.top();
		else L2[i] = 0;
		st2.push(i);
	}
}
void solve() {
	cin >> m >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		a1[i] = a[i];
		a2[i] = m - a[i];
	}
	right1();
	left1();
	right2();
	left2();
//	for(int i = 1; i <= m; i++) cout << R1[i] << " ";
//	cout << endl;
//	for(int i = 1; i <= m; i++) cout << L1[i] << " ";
	int res = 0;
	for(int i = 1; i <= m; i++) {
		int s1 = a1[i] * (R1[i] - L1[i] - 1);
		int s2 = a2[i] * (R2[i] - L2[i] - 1);
		res = max(res, max(s1, s2));
	}
	cout << res << endl;
}
main() {
	solve();
}
