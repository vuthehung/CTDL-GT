#include<bits/stdc++.h>
using namespace std;


void next_greater(int g[], int a[], int n) { // luu mang g la mang chua vi tri dau tien phia ben phai lon hon gia tri dang xet
	stack<int> st;
	for(int i = n; i >= 1; i--) {
		while(!st.empty() && a[st.top()] <= a[i]) st.pop();
		if(!st.empty()) g[i] = st.top();
		else g[i] = -1;
		st.push(i);
	}
}
void smaller(int s[], int a[], int n) { //mang s: luu vi tri dau tien ben phai nho hon gia tri dang xet
	stack<int> st;
	for(int i = n; i >= 1; i--) {
		while(!st.empty() && a[st.top()] >= a[i]) st.pop();
		if(!st.empty()) s[i] = st.top();
		else s[i] = -1;
		st.push(i);
	}
}
void solve() {
	int n; cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	int g[n + 1], s[n + 1];
	next_greater(g, a, n);
	smaller(s, a, n);
	for(int i = 1; i <= n; i++) {
		if(g[i] != - 1 && s[g[i]] != -1) cout << a[s[g[i]]] << " ";
		else cout << -1 << " ";
	}
	cout << endl;
}
main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
