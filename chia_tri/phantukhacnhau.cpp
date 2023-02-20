#include<bits/stdc++.h>
using namespace std;

#define ll long long
main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		ll a[n + 1];
		ll b[n + 1];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n - 1; i++) cin >> b[i];
		for(int i = 0; i < n; i++) {
			if(a[i] != b[i]) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
}
