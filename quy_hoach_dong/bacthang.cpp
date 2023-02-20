#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
	int t; cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		long long f[n + 1] = {0};
		f[0] = f[1] = 1;
		for(int i = 2; i <= n; i++) {
			for(int j = 1; j <= min(i, k); j++) {
				f[i] += f[i - j];
				f[i] %= mod;
			}
		}
		cout << f[n] << endl;
	}	
}
