#include<bits/stdc++.h>
using namespace std;

int n, a[100005], R[100005], L[100005];

void right() { //tim kiem vi tri dau tien ve phia phai co gia tri nho hon gia tri dang xet
	a[n + 1] = 1e9;
	stack<int> st;
	st.push(n + 1);
	for(int i = n; i >= 1; i--) { //duyet tu phai ve trai
		while(!st.empty() && (a[st.top()] >= a[i])) st.pop();
		if(!st.empty()) R[i] = st.top();
		else R[i] = n + 1;
		st.push(i);
	}
}
void left() { // tim kiem vi tri dau tien ve phia trai co gia trii nho hon gia tri dang xet
	a[0] = 1e9;
	stack<int> st;
	st.push(0);
	for(int i = 1; i <= n; i++) {
		while(!st.empty() && (a[st.top()] >= a[i])) st.pop();
		if(!st.empty()) L[i] = st.top();
		else L[i] = 0;
		st.push(i);
	}
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	right();
	left();
	int res = 0;
	for(int i = 1; i <= n; i++) {
		int S = a[i] * (R[i] - L[i] - 1);
		res = max(res, S);
	}
	cout << res << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
