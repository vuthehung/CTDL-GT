#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int n = s.length();
		int res[n][n];
		for(int i = 0; i < n; i++) {
			res[i][i] = 1;
		}
		for(int i = 2; i <= n; i++) {
			for(int j = 0; j < n - i + 1; j++) {
				int k = i + j - 1;
				if(s[k] == s[j] && i == 2) {
					res[j][k] = 2;
				}else if(s[j] == s[k]) {
					res[j][k] = res[j + 1][k - 1] + 2;
				}else {
					res[j][k] = max(res[j + 1][k], res[j][k - 1]);
				}
			}
		}
		cout << n - res[0][n - 1] << endl;
	}
}
