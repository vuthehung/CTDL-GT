#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i] + b[i - 1];
	}
	for(int i = 1; i <= n; i++) {
		if(b[i] - a[i] == (b[n] - a[i]) / 2 && (b[n] - a[i]) % 2 == 0) {
			cout << i << endl;
			return;
		}
	}
	cout << "-1\n";
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
