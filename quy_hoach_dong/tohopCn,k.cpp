#include<bits/stdc++.h>
using namespace std;
/*
to hop C(n, k) = 1 neu k = 0, k = n
			   = C(n - 1, k - 1) + C(n - 1, k)
*/
int a[1001][1001], mod = 1e9 + 7;
int main() {
	a[0][0] = 1;
	for(int i = 1; i < 1001; i++) {
		a[i][0] = 1;
		for(int j = 1; j < 1001; j++) {
			a[i][j] = (a[i - 1][j - 1] % mod + a[i - 1][j] % mod) % mod;
		}
	}
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		cout << a[n][k] << endl;
	}
}
