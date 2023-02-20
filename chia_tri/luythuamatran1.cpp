#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
int n, k;
struct matrix{
	ll f[10][10];
};

matrix operator* (matrix a, matrix b) {
	matrix c;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			c.f[i][j] = 0;
			for(int l = 0; l < n; l++) {
				c.f[i][j] = (c.f[i][j] + (a.f[i][l] * b.f[l][j] % mod)) % mod;
			}
		}
	}
	return c;
}
matrix powM(matrix a, int k) {
	if(k == 1) return a;
	matrix tmp = powM(a, k / 2);
	if(k % 2 == 0) {
		return (tmp * tmp);
	}
	return a * (tmp * tmp);
}
int main() {
	int t; cin >> t;
	while(t--) {
		cin >> n >> k;
		matrix a;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> a.f[i][j];
			}
		}
		matrix c = powM(a, k);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << c.f[i][j] << " ";
			}
			cout << endl;
		}
	}
}
