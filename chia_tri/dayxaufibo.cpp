#include<bits/stdc++.h>
using namespace std;

long long f[100]; // tinh do dai xau fibo thu n

char fiboWord(int n, long long k) {
	if(n == 1) return 'A';
	if(n == 2) return 'B';
	if(k <= f[n - 2]) return fiboWord(n - 2, k);
	return fiboWord(n - 1, k - f[n - 2]);
}
int main() {
	f[0] = 0; f[1] = 1;
	for(int i = 2; i <= 92; i++) f[i] = f[i - 1] + f[i - 2];
	int t; cin >> t;
	while(t--) {
		int n; long long k;
		cin >> n >> k;
		cout << fiboWord(n, k) << endl;
	}	
}
