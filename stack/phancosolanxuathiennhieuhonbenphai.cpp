#include<bits/stdc++.h>
using namespace std;
void right(int r[], int a[], int b[], int n) {
	stack<int> st;
	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() && b[st.top()] <= b[a[i]]) st.pop();
		if(!st.empty()) r[i] = st.top();
		else r[i] = -1;
		st.push(a[i]);
	}
}
void solan_xh(int a[], int b[], int n) {
	for(int i = 0; i < n; i++) {
		b[a[i]]++;
	}
}
void solve() {
	int n, a[100001], b[100001] = {0}, r[100001];
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	solan_xh(a, b, n);
	right(r, a, b, n);
	for(int i = 0; i < n; i++) cout << r[i] << " ";
	cout << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
