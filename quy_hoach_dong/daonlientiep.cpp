#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int f[n];
		for(int i = 0; i < n; i++) {
			f[i] = 1;
			for(int j = i - 1; j >= 1; j--) {
				if(a[i] >= a[j]) {
					f[i] += 1;
				}else break;
			}
 		}
 		for(int i = 0; i < n; i++) cout << f[i] << " ";
 		cout << endl;
	}
}
