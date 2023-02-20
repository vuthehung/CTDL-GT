#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int n, int x) {
	int l = 0, r = n - 1;
	int res = - 1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(a[mid] == x) {
			res = mid;
			r = mid - 1;
		}else if(a[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return res;
}
int main() {
	int t;cin >> t;
	while(t--) {
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int indx = binary_search(a, n, 1);
		if(indx == -1) {
			cout << n << endl;
		}else if(indx == 0) cout << 0 << endl;
		else cout << indx << endl;
	}
}

