#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n, v; cin >> n >> v;
		int w[n + 1], a[n + 1];
		for(int i = 1; i <= n; i++) cin >> w[i];
		for(int i = 1; i <= n; i++) cin >> a[i];
		int dp[n + 1][v + 1];
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= v; j++) {
				dp[i][j] = dp[i - 1][j];
				if(w[i] <= j) {
					dp[i][j] = max(dp[i][j], (dp[i - 1][j - w[i]] + a[i]));
				}
			}
		}
		cout << dp[n][v] << endl;
	}
}
