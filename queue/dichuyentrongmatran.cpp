#include<bits/stdc++.h>
using namespace std;

int a[1005][1005], res[1005][1005];

void solve() {
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	memset(res, -1, sizeof(res));
	queue<pair<int, int> > q;
	q.push({1, 1});
	res[1][1] = 0;
	while(!q.empty()) {
		pair<int, int> t = q.front();
		q.pop();
		int x = t.first, y = t.second;
		if(res[x + a[x][y]][y] == -1) {
			res[x + a[x][y]][y] = res[x][y] + 1;
			q.push({x + a[x][y], y});
		}
		if(res[x][y + a[x][y]] == -1) {
			res[x][y + a[x][y]] = res[x][y] + 1;
			q.push({x, y + a[x][y]});
		} 
		if(res[n][m] != - 1) break;
	}
	cout << res[n][m] << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();	
	}
}
