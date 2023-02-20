#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n; cin >> n;
	int a[n];
	for(int &x : a) cin >> x;
	sort(a, a + n, greater<int>());
	for(int i = 0; i < n / 2; i++) {
		cout << a[i] << " " << a[n - i - 1] << " ";
	}
	if(n % 2 != 0) cout << a[n / 2];
	cout << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}