#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

struct matrix{
	long long f[2][2];
};

matrix operator* (matrix a, matrix b) {
	matrix c;
	for(int i = 0; i <= 1; i++) {
		for(int j = 0; j <= 1; j++) {
			c.f[i][j] = 0;
			for(int k = 0; k <= 1; k++) {
				c.f[i][j] = (c.f[i][j] + (a.f[i][k] * b.f[k][j] % mod)) % mod;
			}
		}
	}
	return c;
}
matrix powM(matrix a, int n) {
	if(n == 1) return a;
	matrix tmp = powM( a, n / 2);
	if(n % 2 == 0) return tmp * tmp;
	return a * tmp * tmp;
}
int fibo_n(int n) {
	matrix a;
	a.f[0][0] = 1; a.f[0][1] = 1; a.f[1][0] = 1; a.f[1][1] = 0;
	matrix res = powM(a, n);
	return res.f[0][1];
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		cout << fibo_n(n) << endl;
	}
}
