#include<bits/stdc++.h>
using namespace std;

bool pytago(int a[], int n) {
	for(int i = 0; i <= n - 3; i++) {
		for(int j = i + 1; j <= n - 2; j++) {
			long long s = a[i] * a[i] + a[j] * a[j];
			double c = sqrt(s);
			if(c == (long long)c) {
				for(int k = j + 1; k < n; k++) {
					if(a[k] == c) return true;
				}
			}
		}
	}
	return false;
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		if(pytago(a, n)) cout << "YES\n";
		else cout << "NO\n";
	}
}
