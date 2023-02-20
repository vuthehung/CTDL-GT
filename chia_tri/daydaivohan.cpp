#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
struct matrix{
	ll f[2][2];
};

matrix operator* (matrix a, matrix b) {
	matrix c;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			c.f[i][j] = 0;
			for(int l = 0; l < 2; l++) {
				c.f[i][j] = (c.f[i][j] + (a.f[i][l] * b.f[l][j] % mod)) % mod;
			}
		}
	}
	return c;
}
matrix powM(matrix a, int n) {
	if(n == 1) return a;
	matrix tmp = powM(a, n / 2);
	if(n % 2 == 0) return tmp * tmp;
	return a * tmp * tmp;
}
int main() {
	int t; cin >> t;
	while(t--) {
		matrix a;
		a.f[0][0] = 1; a.f[0][1] = 1; a.f[1][0] = 1; a.f[1][1] = 0;
		int n; cin >> n;
		matrix res = powM(a, n);
		cout << res.f[0][1] << endl;
	}
}
