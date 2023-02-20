#include<bits/stdc++.h>
using namespace std;

int maxSubArrSum(int a[], int n) {
	int local_max[n] = {0};
	local_max[0] = a[0];
	int res = 0;
	for(int i = 1; i < n; i++) {
		local_max[i] = max(a[i], local_max[i - 1] + a[i]);
		res = max(res, local_max[i]);
	}
	return res;
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << maxSubArrSum(a, n) << endl;
	}
}
