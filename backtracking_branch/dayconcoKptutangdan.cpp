#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[20], x[20];

int kt_tangdan() {
	for(int i = 1; i <= k - 1; i++) {
		if(a[x[i]] > a[x[i + 1]]) return 0;
	}
	return 1;
}
void b_t(int i) {
	for(int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if(i == k) {
			if(kt_tangdan()) {
				for(int i = 1; i <= k; i++) {
					cout << a[x[i]] << " ";
				}
				cout << endl;
				}
		}else b_t(i + 1);
	}
}
void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	b_t(1);
}
int main(){
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
