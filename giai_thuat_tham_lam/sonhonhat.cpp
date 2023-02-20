#include<bits/stdc++.h>
using namespace std;

void solve() {
	int s, d; cin >> s >> d;
	if(s > 9 * d) {
		cout << "-1\n";
	}
	else {
		int a[d];
		--s;
		for(int i = d - 1; i > 0; i--) {
			if(s >= 9) {
				a[i] = 9; s -= 9;
			}else {
				a[i] = s; s = 0;
			}
		}
		a[0] = s + 1;
		for(int i = 0; i < d; i++) {
			cout << a[i];
		}
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
		cout << endl;
	}
}
