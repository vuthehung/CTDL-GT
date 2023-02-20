#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector<long long> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long res = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				long long tmp = lower_bound(a.begin() + j + 1, a.end(), k - (a[i] + a[j])) - a.begin();
//				if(tmp == n) {
//					continue;
//				}
//				else {
					if((a[i] + a[j] + a[tmp]) <= k ) {
						res = max(res, a[i] + a[j] + a[tmp]);
					}
				}
			//}
		}
		cout << res << endl;
	}
}
