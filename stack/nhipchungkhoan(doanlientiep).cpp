#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n + 1], L[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	stack<int> st;
	for(int i = 1; i <= n; i++) {
		while(!st.empty() && a[st.top()] <= a[i]) st.pop();
		if(!st.empty()) L[i] = i - st.top();
		else L[i] = i;
		st.push(i);
	}
	for(int i = 1; i <= n; i++) cout << L[i] << " ";
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
		cout << endl;
	}
}
