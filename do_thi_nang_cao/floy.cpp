#include<bits/stdc++.h>
using namespace std;

const int INF = (int) 1e9 + 1;
int d[105][105];
int n, m;

void inp() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		d[x][y] = d[y][x] = w;
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int q; cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << d[u][v] << endl;
	}
}
int main() {
	inp();
}
