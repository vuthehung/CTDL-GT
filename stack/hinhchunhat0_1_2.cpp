#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, m;
int a[505][505], R[1000005], L[100005], f[1000005];

void right() {
	stack<int> st;
	f[m + 1] = 1e9;
	st.push(n + 1);
	for(int i = m; i >= 1; i--) {
		while(!st.empty() && f[st.top()] >= f[i]) st.pop();
		if(!st.empty()) R[i] = st.top();
		else R[i] = n + 1;
		st.push(i);
	}
}
void left() {
	stack<int> st;
	f[0] = 1e9;
	st.push(0);
	for(int i = 1; i <= m; i++) {
		while(!st.empty() && f[st.top()] >= f[i]) st.pop();
		if(!st.empty()) L[i] = st.top();
		else L[i] = 0;
		st.push(i);
	}
}
void solve() {
	cin >> n >> m;
	for(int i = 0; i <= m; i++) f[i] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if(a[i][j] == 1) {
				f[j] += 1;
			}
		}
	}
	right();
	left();
	int S = 0;
	for(int i = 1; i <= m; i++) {
		int ans = f[i] * (R[i] - L[i] - 1);
		S = max(S, ans);
	}
	cout << S << endl;
}
main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
