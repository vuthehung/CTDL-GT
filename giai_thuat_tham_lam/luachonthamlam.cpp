#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, s; cin >> n >> s;
	if(s > 9 * n || (s == 0 && n > 1)) {
		cout << "-1 -1";
	}else {
		int tmp = s;
		int a[n];
		--s;
		for(int i = n - 1; i > 0; i--) {
			if(s >= 9) {
				a[i] = 9; s -= 9;
			}else {
				a[i] = s; s = 0;
			}
		}
		a[0] = s + 1;
		int b[n];
		for(int i = 0; i < n; i++) b[i] = a[i];
		reverse(b, b + n);
		for(int i = 0; i < n; i++) cout << a[i];
		cout << " ";
		if(tmp == 1) {
			for(int i = 0; i < n; i++) cout << a[i];
		}else {
			for(int i = 0; i < n; i++) cout << b[i];
		}
	}
}
int main() {
	int t = 1;
	while(t--) {
		solve();
	}
}
