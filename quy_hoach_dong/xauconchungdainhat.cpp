#include<bits/stdc++.h>
using namespace std;
int solve(string s1, string s2) {
	int n = s1.size(), m = s2.size();
	int res = 0;
	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			res = max(res, dp[i][j]);
		}
	}
	return res;
}
int main() {
	int t; cin >> t;
	while(t--) {
		string s1, s2;
		cin >> s1 >> s2;
		cout << solve(s1, s2) << endl;
	}	
}
