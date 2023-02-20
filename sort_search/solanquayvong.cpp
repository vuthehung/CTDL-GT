#include<bits/stdc++.h>
using namespace std;


int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		long long a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int j;
		for(j = 0; j < n; j++) {
			if(a[j] > a[j + 1]) break;
		}
		if(j == n) cout << 0;
		else cout << j + 1;
		cout << endl;
	}
}

