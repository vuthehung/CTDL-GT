#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum % 2 == 1) {
		cout << "NO\n";
		return;
	}
	bool sub[sum/2 + 1];
	memset(sub, false, sizeof(sub));
	for(int i = 0; i < n; i++) {
		for(int j = sum / 2; j >= a[i]; j--) {
			if(sub[j - a[i]] || j == a[i]) {
				sub[j] = true;
			}
		}
	}
	if(sub[sum/2]) {
		cout << "YES\n";
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
