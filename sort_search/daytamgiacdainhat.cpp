#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	int a[n], f[n], g[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	f[0] = g[n - 1] = 1;
	for(int i = 1; i < n; i++) {
		if(a[i] > a[i - 1]) {
			f[i] = f[i - 1] + 1;
		}else f[i] = 1;
	}
	for(int i = n - 2; i >= 0; i--) {
		if(a[i] > a[i + 1]) {
			g[i] = g[i + 1] + 1;
		}else g[i] = 1;
	}
	int res = 1;
	for(int i = 0; i < n; i++) {
		res = max(res, f[i] + g[i] - 1);
	}
	cout << res << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();		
	}
}
