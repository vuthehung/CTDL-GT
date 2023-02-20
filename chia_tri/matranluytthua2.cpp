#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = 1e9 + 7;

int n, k;
struct matrix{
	ll f[10][10];
};
matrix operator* (matrix a, matrix b) {
	matrix c;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			c.f[i][j] = 0;
			for(int l = 0;l < n; l++) {
				c.f[i][j] = (c.f[i][j] + (a.f[i][l] * b.f[l][j] % mod)) % mod;
			}
		}
	}
	return c;
}
matrix powM(matrix a, int k) {
	if(k == 1) return a;
	matrix tmp = powM(a, k / 2);
	if(k % 2 == 0) return tmp * tmp;
	return a * tmp * tmp;
}
ll powMatrix(matrix a, int k) {
	matrix res = powM(a, k);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans = (ans + res.f[i][n - 1]) % mod;
	}
	return ans;
}
int main() {
	int t; cin >> t;
	while(t--) {
		matrix a;
		cin >> n >> k;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> a.f[i][j];
			}
		}
		cout << powMatrix(a, k) << endl;
	}
}
