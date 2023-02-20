#include<bits/stdc++.h>
using namespace std;

int main() {
	long long f[100];
	f[1] = 1; f[2] = 2; f[3] = 4;
	for(int i = 4; i <= 100; i++) f[i] = f[i - 1] + f[i - 2] + f[i - 3];
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		cout << f[n] << endl;
	}
}
