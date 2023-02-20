#include<bits/stdc++.h>
using namespace std;
#define int long long

void Right(int R[], int n, int a[]) {
	stack <int> st;
	for(int i=n-1; i>=0; i--) {
		while(!st.empty() && a[st.top()] >= a[i]) st.pop();
		if(!st.empty()) R[i] = st.top();
		else R[i] = -1;
		st.push(i);
	}
}

void Left(int L[], int n, int a[]) {
	stack <int> st;
	for(int i=0; i<n; i++) {
		while(!st.empty() && a[st.top()] >= a[i]) st.pop();
		if(!st.empty()) L[i] = st.top();
		else L[i] = -1;
		st.push(i);
	}
}

void Solve() {
	int n, a[100005], R[100005], L[100005];
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	Right(R, n, a);
	Left(L, n, a);
	int ans = 0;
	for(int i=1; i<n; i++) {
		int x = L[i], y = R[i];
		if(y == -1) y = n;
		int calc = y-x-1;
		if(calc >= a[i]) ans = max(ans, a[i]);
	}
	cout << ans << endl;
}

main() {
	int t; cin >> t;
	while(t--) {
		Solve();
	}
}



