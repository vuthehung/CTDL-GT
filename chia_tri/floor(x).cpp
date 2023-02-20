#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int res(ll a[], ll x, int l, int r) {
	int ans = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(a[mid] <= x) {
			ans = mid + 1;
			l = mid + 1;
		}
		else if(a[mid] > x) r = mid - 1; 
	}
	return ans;
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; ll x; cin >> n >> x;
		ll a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << res(a, x, 0, n - 1) << endl;
	}	
}
