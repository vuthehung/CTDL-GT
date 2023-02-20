#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll f[100];

int dayxau_bina(int n, ll k) {
	if(n == 1) return 0;
	if(n == 2) return 1;
	if(k <= f[n - 2]) return dayxau_bina(n - 2, k);
	return dayxau_bina(n - 1, k - f[n - 2]);
}
int main() {
	f[0] = 0; f[1] = 1;
	for(int i = 2; i <= 92; i++) f[i] = f[i - 1] + f[i - 2];
	int t; cin >> t;
	while(t--) {
		int n; ll k; cin >> n >> k;
		cout << dayxau_bina(n, k) << endl;		
	}
}
