#include<bits/stdc++.h>
using namespace std;

int last_x(int a[], int l, int r, int n, int x) { //phan tu cuoi cung nho hon x
	int res = - 1;
	while(l <= r) {
		int m = (l + r) / 2;
		if(a[m] < x) {
			res = m;
			l = m + 1;
		}else r = m - 1;
	}
	return res;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		long long ans = 0;
		for(int i = 0; i < n; i++) {
			int res = last_x(a, i + 1, n - 1, n, k + a[i]);
			if(res != - 1) {
				ans += res - i;
			}
		}
		cout << ans << endl;
	}
}
