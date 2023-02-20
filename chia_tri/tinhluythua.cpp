#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int powMod(int a, int b) {
	if(b == 0) return 1;
	int tmp = powMod(a, b / 2);
	if(b % 2 == 0) {
		return (tmp * tmp) % mod;
	}
	return (a * (tmp * tmp) % mod) % mod;
}
int main() {
	while(1) {
		int a; int b;
		cin >> a >> b;
		if(a == 0 && b == 0) break;
		cout << powMod(a, b) << endl;
	}
}
