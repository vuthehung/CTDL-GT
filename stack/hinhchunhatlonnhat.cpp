#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a[100005], R[100005], L[100005];

void Right() {    // tim vi tri j dau tien ve phia phai co a[j] < a[dang xet]
	stack <int> st;
	a[n+1] = 1e9;
	st.push(n+1);
	for(int i=n; i>=1; i--) {
		while(!st.empty() && a[st.top()] >= a[i]) st.pop();
		if(!st.empty()) R[i] = st.top();
		else R[i] = n+1;
		st.push(i);
	}
}

void Left() { // tim vi tri j dau tien ve phia trai co a[j] < a[dang xet]
	stack <int> st;
	a[0] = 1e9;	
	st.push(0);
	for(int i=1; i<=n; i++) {
		while(!st.empty() && a[st.top()] >= a[i]) st.pop();
		if(!st.empty()) L[i] = st.top();
		else L[i] = 0;
		st.push(i);
	}
}

void Solve() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	Right();
	Left();
	int ans = 0;
	for(int i=1; i<=n; i++) {
		int area = a[i]*(R[i]-L[i]-1);
		ans = max(ans, area);
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++) cout << R[i] << " ";
	cout << endl;
	for(int i = 1; i <= n; i++) cout << L[i] << " ";
}

main() {
	int t; cin >> t;
	while(t--) {
		Solve();
	}
}


