#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1001][1001], res[1001][1001];
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	memset(res, -1, sizeof(res));
	res[1][1] = 0;
	queue<pair<int, int> > q;
	q.push({1, 1});
	while(!q.empty()) {
		pair<int, int> u = q.front(); q.pop();
		int s = u.first, t = u.second;
		int d = abs(a[s][t] - a[s + 1][t]);
		int r = abs(a[s][t] - a[s][t + 1]);
		int c = abs(a[s][t] - a[s + 1][t + 1]);
		if(res[s + d][t] == -1) {
			res[s + d][t] = res[s][t] + 1;
			q.push({s + d, t});
		}
		if(res[s][t + r] == -1) {
			res[s][t + r] = res[s][t] + 1;
			q.push({s, t + r});
		}
		if(res[s + c][t + c] == -1) {
			res[s + c][t + c] = res[s][t] + 1;
			q.push({s + c, t + c});
		}
		if(res[n][m] != -1) break;
	}
	cout << res[n][m] << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
